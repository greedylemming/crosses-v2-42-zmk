#ifndef ZMK_HID_OVERRIDE_H
#define ZMK_HID_OVERRIDE_H

/* 1. Import core ZMK framework structs and constants */
#include_next <zmk/hid.h>

/* 2. Overwrite the baseline descriptor layout with 2000 CPI macOS vectors */
#ifdef ZMK_HID_REPORT_DESC_POINTING_BASE
#undef ZMK_HID_REPORT_DESC_POINTING_BASE

#define ZMK_HID_REPORT_DESC_POINTING_BASE(usages) \
    HID_USAGE_PAGE(HID_USAGE_GD), \
    HID_USAGE(HID_USAGE_GD_POINTER), \
    HID_COLLECTION(HID_COLLECTION_PHYSICAL), \
        usages \
        HID_USAGE_PAGE(HID_USAGE_GD), \
        HID_USAGE(HID_USAGE_GD_X), \
        HID_USAGE(HID_USAGE_GD_Y), \
        HID_LOGICAL_MINIMUM(0x81), \
        HID_LOGICAL_MAXIMUM(0x7f), \
        HID_REPORT_SIZE(8), \
        HID_REPORT_COUNT(2), \
        HID_INPUT(HID_DATA_VARIABLE_RELATIVE), \
        \
        /* --- HIGH RESOLUTION VERTICAL SCROLL (WHEEL) --- */ \
        HID_USAGE_PAGE(HID_USAGE_GD), \
        HID_USAGE(HID_USAGE_GD_WHEEL), \
        HID_LOGICAL_MINIMUM(0x81), \
        HID_LOGICAL_MAXIMUM(0x7f), \
        0x35, 0x0A, 0xFB, /* PHYSICAL_MINIMUM (-1270) */ \
        0x45, 0xF6, 0x04, /* PHYSICAL_MAXIMUM (1270) */ \
        0x55, 0x0F,       /* UNIT_EXPONENT (-1) */ \
        0x65, 0x11,       /* UNIT (SI Linear: Inches) */ \
        HID_REPORT_SIZE(8), \
        HID_REPORT_COUNT(1), \
        HID_INPUT(HID_DATA_VARIABLE_RELATIVE), \
        \
        /* --- HIGH RESOLUTION HORIZONTAL SCROLL (PAN) --- */ \
        HID_USAGE_PAGE(HID_USAGE_CONSUMER), \
        HID_USAGE_16(HID_USAGE_CONSUMER_AC_PAN), \
        HID_LOGICAL_MINIMUM(0x81), \
        HID_LOGICAL_MAXIMUM(0x7f), \
        0x35, 0x0A, 0xFB, /* PHYSICAL_MINIMUM (-1270) */ \
        0x45, 0xF6, 0x04, /* PHYSICAL_MAXIMUM (1270) */ \
        0x55, 0x0F,       /* UNIT_EXPONENT (-1) */ \
        0x65, 0x11,       /* UNIT (SI Linear: Inches) */ \
        HID_REPORT_SIZE(8), \
        HID_REPORT_COUNT(1), \
        HID_INPUT(HID_DATA_VARIABLE_RELATIVE), \
    HID_END_COLLECTION
#endif

#endif /* ZMK_HID_OVERRIDE_H */
