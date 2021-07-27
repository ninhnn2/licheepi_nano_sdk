#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define GPIO_REG_BASE   0x01C20800      //GPIO physical base address (small page 4kb)
#define MAP_SIZE        0x400 //MMU page size
#define GPIO_BASE_OFFSET (GPIO_REG_BASE & 0X00000FFF) //GPIO base address offset calculation
#define GPIO_PAGE_OFFSET (GPIO_REG_BASE & 0XFFFFF000) //Get page offset

#define rPE_CFG0 0X90   //PE_CFG0 register address offset
#define rPE_DAT 0XA0    //PE_DAT register address offset
#define rPE_PULL0 0XAC  //PE_PULL0 register address offset

int  GPIOE_456_ON(unsigned char *MAP_BASE);//Light up the 3 LEDs PE4, PE5, PE6
int  GPIOE_456_OFF(unsigned char *MAP_BASE);//Turn off the 3 LEDs of PE4, PE5, PE6

int main(int argc, char **argv)
{
	static int dev_fd;
	unsigned char *map_base;
	/*Parameter verification*/
	if(argc!=2 || (strcmp(argv[1],"on") && strcmp(argv[1],"off"))){
		printf("argv_error!please input 'on' or 'off'!\n");
		exit (0);
	}

	dev_fd = open("/dev/mem", O_RDWR );
	if (dev_fd < 0){
		printf("open(/dev/mem) failed.\n");
		return 0;
	}

	map_base = (unsigned char *)mmap(NULL, 0x400,PROT_READ | PROT_WRITE, MAP_SHARED,dev_fd, GPIO_PAGE_OFFSET); //Map the physical address to the virtual address
	if(*map_base) {
		printf("mmap_fail!\n"); //Whether the mapping is successful
	}

	if(!strcmp(argv[1],"on")) {
		GPIOE_456_ON(map_base); //Light up the 3 LEDs PE4, PE5, PE6
	}

	if(!strcmp(argv[1],"off")) GPIOE_456_OFF(map_base);//Turn off the 3 LEDs of PE4, PE5, PE6

	if(dev_fd) close(dev_fd);
	munmap(map_base,MAP_SIZE);//Remove the mapping relationship
	return 0;
}

//GPIOE_456_ON
int  GPIOE_456_ON(unsigned char *MAP_BASE) {
	unsigned int PE_CFG0,PE_DAT;
	PE_CFG0=*(volatile unsigned int *)(MAP_BASE+GPIO_BASE_OFFSET+rPE_CFG0);
	PE_DAT=*(volatile unsigned int *)(MAP_BASE+GPIO_BASE_OFFSET+rPE_DAT);
	*(volatile unsigned int *)(MAP_BASE+GPIO_BASE_OFFSET+rPE_CFG0)=((PE_CFG0 & 0XF000FFFF)|0X01110000);
	*(volatile unsigned int *)(MAP_BASE+GPIO_BASE_OFFSET+rPE_DAT)=((PE_DAT & 0XFFFFFF8F)|0X00000070);
}

//GPIOE_456_OFF
int  GPIOE_456_OFF(unsigned char *MAP_BASE) {
	unsigned int PE_CFG0,PE_DAT;
	PE_CFG0=*(volatile unsigned int *)(MAP_BASE+GPIO_BASE_OFFSET+rPE_CFG0);
	PE_DAT=*(volatile unsigned int *)(MAP_BASE+GPIO_BASE_OFFSET+rPE_DAT);
	*(volatile unsigned int *)(MAP_BASE+GPIO_BASE_OFFSET+rPE_CFG0)=((PE_CFG0 & 0XF000FFFF)|0X01110000);
	*(volatile unsigned int *)(MAP_BASE+GPIO_BASE_OFFSET+rPE_DAT)=((PE_DAT & 0XFFFFFF8F));
}
