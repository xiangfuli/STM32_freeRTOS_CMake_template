#ifndef USBD_DESC_H
#define USBD_DESC_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "usbd_def.h"

#define USB_DEVICE_DESCRIPTOR_TYPE              0x01
#define USB_CONFIGURATION_DESCRIPTOR_TYPE       0x02
#define USB_STRING_DESCRIPTOR_TYPE              0x03
#define USB_INTERFACE_DESCRIPTOR_TYPE           0x04
#define USB_ENDPOINT_DESCRIPTOR_TYPE            0x05
#define USB_SIZ_DEVICE_DESC                     18
#define USB_SIZ_STRING_LANGID                   4

extern uint8_t *     USBD_USR_DeviceDescriptor( uint8_t speed , uint16_t *length);
extern uint8_t *     USBD_USR_LangIDStrDescriptor( uint8_t speed , uint16_t *length);
extern uint8_t *     USBD_USR_ManufacturerStrDescriptor ( uint8_t speed , uint16_t *length);
extern uint8_t *     USBD_USR_ProductStrDescriptor ( uint8_t speed , uint16_t *length);
extern uint8_t *     USBD_USR_SerialStrDescriptor( uint8_t speed , uint16_t *length);
extern uint8_t *     USBD_USR_ConfigStrDescriptor( uint8_t speed , uint16_t *length);
extern uint8_t *     USBD_USR_InterfaceStrDescriptor( uint8_t speed , uint16_t *length);
extern USBD_DEVICE USR_desc;

#ifdef __cplusplus
    }
#endif

#endif /* USBD_DESC_H */
