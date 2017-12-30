#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

// As cubemx initialises all hardware, all we have to do is import the hal header. We can then twiddle pins and write data out via spi as required.
//  Maybe DMA could be used, but that would require a smarter version of the driver.
#include <stm32f3xx_hal.h>

//#define ST7735_TYPE_RED 		TRUE
#define ST7735_TYPE_GREEN 		TRUE
//#define ST7735_TYPE_ST7735B TRUE

// seems the easiest way to get access to the appropriate handle
extern SPI_HandleTypeDef hspi2;

static GFXINLINE void init_board(GDisplay *g){
	g->board = 0;
	
	HAL_GPIO_WritePin(SPI2_DC_GPIO_Port, SPI2_DC_Pin, GPIO_PIN_SET);
	
	// board is setup via cubemx
}

static GFXINLINE void post_init_board(GDisplay *g){
	(void)g;
}

static GFXINLINE void set_backlight(GDisplay *g, int bright){
	(void)g;
}

static GFXINLINE void setpin_reset(GDisplay *g, bool_t state){
	(void)g;
	
	if(state){
		// nReset (active low)
		HAL_GPIO_WritePin(SPI2_RST_GPIO_Port, SPI2_RST_Pin, GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin(SPI2_RST_GPIO_Port, SPI2_RST_Pin, GPIO_PIN_SET);
	}
}
static GFXINLINE void acquire_bus(GDisplay *g){
	HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
}
static GFXINLINE void release_bus(GDisplay *g){
	HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);
}
static GFXINLINE void write_index(GDisplay *g, uint8_t cmd){
	HAL_GPIO_WritePin(SPI2_DC_GPIO_Port, SPI2_DC_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, (uint8_t *)&cmd, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(SPI2_DC_GPIO_Port, SPI2_DC_Pin, GPIO_PIN_SET);
}

static GFXINLINE void write_data(GDisplay *g, uint8_t data){
	HAL_SPI_Transmit(&hspi2, (uint8_t *)&data, 1, HAL_MAX_DELAY);
}

#endif
