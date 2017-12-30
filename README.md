Test project of getting uGfx running on the stm32f3discovery with an ST7735 display and FreeRTOS with low level hardware configured via STM32CubeMX.

Building (hopefully):
 - open f3_gfx/f3_gfx.ioc in Stm32CubeMX and generate code
 - open f3_gfx/MDK-ARM/f3_gfx.uvprojx in MDK-ARMv5
 - (maybe fixed eventually) CubeMX specifies an old configuration for the chip, so you might have to select STM32F303VCTx
 - build
 - debug/download/whatever, profit!
