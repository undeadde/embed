#define GPBCON (*(volatile unsigned long *)0x56000010)
#define GPBDAT (*(volatile unsigned long *)0x56000014)

#define GPFCON (*(volatile unsigned long *)0x56000050)
#define GPFDAT (*(volatile unsigned long *)0x56000054)

#define GPGCON (*(volatile unsigned long *)0x56000060)
#define GPGDAT (*(volatile unsigned long *)0x56000064)

#define GPB5_out (1<<(5*2))
#define GPB6_out (1<<(6*2))
#define GPB7_out (1<<(7*2))
#define GPB8_out (1<<(8*2))

#define GPG11_in ~(3<<(11*2))
#define GPG3_in ~(3<<(3*2))
#define GPF2_in ~(3<<(2*2))
#define GPF0_in ~(3<<(0*2))

int main()
{
    unsigned long dwDat;

    GPBCON = GPB5_out | GPB6_out | GPB7_out | GPB8_out;

    GPGCON = GPG3_in & GPG11_in;

    GPFCON = GPF0_in & GPF2_in;

    while(1)
    {
        dwDat = GPGDAT;

        if(dwDat & (1<<11))
            GPBDAT |= (1<<5);
        else
            GPBDAT &= ~(1<<5);

        if(dwDat & (1<<3))
            GPBDAT |= (1<<6);
        else
            GPBDAT &= ~(1<<6);

        dwDat = GPFDAT;

        if(dwDat & (1<<2))
            GPBDAT |= (1<<7);
        else
            GPBDAT &= ~(1<<7);

        if(dwDat & (1<<0))
            GPBDAT |= (1<<8);
        else
            GPBDAT &= ~(1<<8);
    }

    return 0;
}
