#include <errno.h>
#include "afifo.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"
void BUG_ON(bool b);

unsigned int roundup_pow_of_two(unsigned int size);


int spin_lock_irqrestore(spinlock_t* lock,unsigned int flags)
{
	//flags = (unsigned int)lock+1;
	return flags;
}
int spin_unlock_irqrestore(spinlock_t* lock,unsigned int flags)
{
	//flags = (unsigned int)lock+1;
		return flags;

}



bool is_power_of_2(int n) {
//    int i,j;
    if(n<=0)
        return false;
    if(n==1)
        return true;
    while(n!=1)
    {
        if(n%2==0)
            n=n/2;
        else
            return false;
    }
    return true;
}



void* kmalloc(size_t i) {
    return malloc(i);
}

void kfree(unsigned char *buffer) {
    free(buffer);
}
struct afifo *afifo_init(unsigned char *buffer, unsigned int size, spinlock_t *lock)
{
    struct afifo *fifo;
    /* size must be a power of 2 */
    BUG_ON(!is_power_of_2(size));
    fifo = kmalloc(sizeof(struct afifo));
    if (!fifo)
        return 0;
    fifo->buffer = buffer;
    fifo->size = size;
    fifo->in = fifo->out = 0;
    fifo->lock = lock;

    return fifo;
}


struct afifo *afifo_alloc(unsigned int size, spinlock_t *lock)
{
    unsigned char *buffer;
    struct afifo *ret;
    if (!is_power_of_2(size)) {
        BUG_ON(size > 0x80000000);
        size = roundup_pow_of_two(size);
    }
    buffer = kmalloc(size);
    if (!buffer)
        return 0;
    ret = afifo_init(buffer, size, lock);

    if ((ret==0))
        kfree(buffer);
    return ret;
}



static unsigned int fls(unsigned int x)
{
    unsigned int position;
    unsigned int i;
    if(0 != x)
    {
        for (i = (x >> 1), position = 0; i != 0; ++position)
            i >>= 1;
    }
    else
    {
        position = -1;
    }
    return position+1;
}
unsigned int roundup_pow_of_two(unsigned int size) {
    return 1UL << fls(size - 1);
}

void BUG_ON(bool b) {
    while(b){}
}


unsigned int __afifo_in(struct afifo *fifo, const unsigned char *buffer, unsigned int len)
{
    unsigned int l;
    //buffer中空的长度
    len = min(len, fifo->size - fifo->in + fifo->out);
    /*
     * Ensure that we sample the fifo->out index -before- we
     * start putting bytes into the afifo.
     */
    // smp_mb();
    /* first put the data starting from fifo->in to buffer end */
    l = min(len, fifo->size - (fifo->in & (fifo->size - 1)));
    memcpy(fifo->buffer + (fifo->in & (fifo->size - 1)), buffer, l);
    /* then put the rest (if any) at the beginning of the buffer */
    memcpy(fifo->buffer, buffer + l, len - l);

    /*
     * Ensure that we add the bytes to the afifo -before-
     * we update the fifo->in index.
     */
    // smp_wmb();
    fifo->in += len;  //每次累加，到达最大值后溢出，自动转为0
    return len;
}

unsigned int __afifo_out(struct afifo *fifo, unsigned char *buffer, unsigned int len)
{
    unsigned int l;
    //有数据的缓冲区的长度
    len = min(len, fifo->in - fifo->out);
    /*
     * Ensure that we sample the fifo->in index -before- we
     * start removing bytes from the afifo.
     */
    //  smp_rmb();
    /* first get the data from fifo->out until the end of the buffer */
    l = min(len, fifo->size - (fifo->out & (fifo->size - 1)));
    memcpy(buffer, fifo->buffer + (fifo->out & (fifo->size - 1)), l);
    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(buffer + l, fifo->buffer, len - l);
    /*
     * Ensure that we remove the bytes from the afifo -before-
     * we update the fifo->out index.
     */
    // smp_mb();
    fifo->out += len; //每次累加，到达最大值后溢出，自动转为0
    return len;
}

unsigned int __afifo_in_data(struct afifo *fifo, const unsigned char *buffer, unsigned int len)
{
    unsigned int l;
    //buffer中空的长度
    len = min(len, fifo->size - fifo->in + fifo->out);
    /*
     * Ensure that we sample the fifo->out index -before- we
     * start putting bytes into the afifo.
     */
    // smp_mb();
    /* first put the data starting from fifo->in to buffer end */
    l = min(len, fifo->size - (fifo->in & (fifo->size - 1)));
    memcpy(fifo->buffer + (fifo->in & (fifo->size - 1)), buffer, l);
    /* then put the rest (if any) at the beginning of the buffer */
    memcpy(fifo->buffer, buffer + l, len - l);

    /*
     * Ensure that we add the bytes to the afifo -before-
     * we update the fifo->in index.
     */
    // smp_wmb();
    //fifo->in += len;  //每次累加，到达最大值后溢出，自动转为0
    return len;
}

unsigned int __afifo_out_data(struct afifo *fifo, unsigned char *buffer, unsigned int len)
{
    unsigned int l;
    //有数据的缓冲区的长度
    len = min(len, fifo->in - fifo->out);
    /*
     * Ensure that we sample the fifo->in index -before- we
     * start removing bytes from the afifo.
     */
    //  smp_rmb();
    /* first get the data from fifo->out until the end of the buffer */
    l = min(len, fifo->size - (fifo->out & (fifo->size - 1)));
    memcpy(buffer, fifo->buffer + (fifo->out & (fifo->size - 1)), l);
    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(buffer + l, fifo->buffer, len - l);
    /*
     * Ensure that we remove the bytes from the afifo -before-
     * we update the fifo->out index.
     */
    // smp_mb();
    //fifo->out += len; //每次累加，到达最大值后溢出，自动转为0
    return len;
}





 inline unsigned int afifo_get_used(struct afifo* afifo)
{
    return (afifo->in - afifo->out);
}
 inline unsigned int afifo_get_free(struct afifo* afifo)
{
    return afifo->size - afifo_get_used(afifo);
}




 inline unsigned int afifo_in_data(struct afifo* fifo, const unsigned char* buffer, unsigned int len)
{
    unsigned long flags;
    unsigned int ret;
    spin_lock_irqrestore(fifo->lock, flags);
    ret = __afifo_in_data(fifo, buffer, len);
    spin_unlock_irqrestore(fifo->lock, flags);
    return ret;
}
 inline unsigned int afifo_add_in(struct afifo* fifo, unsigned int len)
{
    // unsigned long flags;
    unsigned int ret;
    // unsigned int l;
    // buffer中空的长度
    len = min(len, fifo->size - fifo->in + fifo->out);
    fifo->in += len; // 每次累加，到达最大值后溢出，自动转为0
    ret = len;
    return ret;
}
  unsigned int afifo_in(struct afifo* fifo, const unsigned char* buffer, unsigned int len)
{
    unsigned long flags;
    unsigned int ret;
    spin_lock_irqrestore(fifo->lock, flags);
    ret = __afifo_in(fifo, buffer, len);
    spin_unlock_irqrestore(fifo->lock, flags);
    return ret;
}

static inline unsigned int afifo_out_data(struct afifo* fifo, unsigned char* buffer, unsigned int len)
{
    unsigned long flags;
    unsigned int ret;
    spin_lock_irqrestore(fifo->lock, flags);
    ret = __afifo_out_data(fifo, buffer, len);

    spin_unlock_irqrestore(fifo->lock, flags);
    return ret;
}

static inline unsigned int afifo_add_out(struct afifo* fifo, unsigned int len)
{
    unsigned int ret;
    len = min(len, fifo->in - fifo->out);
    fifo->out += len; // 每次累加，到达最大值后溢出，自动转为0
    ret = len;
    return ret;
}

 inline unsigned int afifo_out(struct afifo* fifo, unsigned char* buffer, unsigned int len)
{
    unsigned long flags;
    unsigned int ret;
    spin_lock_irqrestore(fifo->lock, flags);
    ret = __afifo_out(fifo, buffer, len);

    spin_unlock_irqrestore(fifo->lock, flags);
    return ret;
}
/**
 * @brief 获取in在数组的地址
 *
 * @param fifo
 * @return uint8_t*
 */
 inline uint8_t* afifo_get_in_pointer(struct afifo* fifo)
{
    return (fifo->buffer + (fifo->in & (fifo->size - 1)));
}
 inline uint8_t* afifo_get_out_pointer(struct afifo* fifo)
{
    return (fifo->buffer + (fifo->out & (fifo->size - 1)));
}
/**
 * @brief 获取剩余的连续的空间
 *
 * @param fifo
 * @return unsigned int
 */
static inline unsigned int afifo_get_free_block(struct afifo* fifo)
{
    return (unsigned int)(fifo->size - (fifo->out & (fifo->size - 1)));
}
/**
 * @brief 获取fifo的大小
 *
 * @param fifo
 * @return unsigned int
 */
 inline unsigned int afifo_size(struct afifo* fifo)
{
    return (unsigned int)(fifo->size);
}
/**
 * @brief 重置fifo
 *
 * @param fifo
 */
 inline void afifo_reset(struct afifo* fifo)
{
    unsigned long flags;
    spin_lock_irqrestore(fifo->lock, flags);
    fifo->in = fifo->out = 0;
    spin_unlock_irqrestore(fifo->lock, flags);
}
