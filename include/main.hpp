#ifndef MAIN_H
#define MAIN_H

#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx.h"

#include "usbd_core.h"
#include "usbd_cdc_core.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"
#include "usbd_usr.h"

int main(void);

#endif /* MAIN_H */
