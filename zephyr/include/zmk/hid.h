#ifndef ZMK_HID_OVERRIDE_H
#define ZMK_HID_OVERRIDE_H

/* 1. Pull in all the original structures and baseline macros first */
#include_next <zmk/hid.h>

/* 
 * 2. Overwrite the baseline descriptor layout to match PR #3483 exactly.
 *    Using ZMK's native 16-bit helper macros avoids manual byte-splitting 
 *    mistakes and preserves perfect descriptor alignment.
 */
#ifdef ZMK_HID_REPORT_DESC_POINTING_BASE
#undef ZMK_HID_REPORT_DESC_POINTING_BASE

/* 
 * Math mapping for a 2000 CPI sensor:
 * Physical Range = (Logical Range * 10) / Target CPI
 * (254 * 10) / 2000 = 1.27 inches.
 * Bound symmetrically: -1270 to 1270 (expressed as 0xFB0A to 0x04F6).
 */
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
        HID_PHYSICAL_MINIMUM_16(0x0A, 0xFB), /* -1270 */ \
        HID_PHYSICAL_MAXIMUM_16(0xF6, 0x04), /*  1270 */ \
        0x55, 0x0F,                          /* UNIT_EXPONENT (-1) */ \
        0x65, 0x11,                          /* UNIT (SI Linear: Inches) */ \
        HID_REPORT_SIZE(8), \
        HID_REPORT_COUNT(1), \
        HID_INPUT(HID_DATA_VARIABLE_RELATIVE), \
        \
        /* --- HIGH RESOLUTION HORIZONTAL SCROLL (PAN) --- */ \
        HID_USAGE_PAGE(HID_USAGE_CONSUMER), \
        HID_USAGE_16(HID_USAGE_CONSUMER_AC_PAN), \
        HID_LOGICAL_MINIMUM(0x81), \
        HID_LOGICAL_MAXIMUM(0x7f), \
        HID_PHYSICAL_MINIMUM_16(0x0A, 0xFB), /* -1270 */ \
        HID_PHYSICAL_MAXIMUM_16(0xF6, 0x04), /*  1270 */ \
        0x55, 0x0F,                          /* UNIT_EXPONENT (-1) */ \
        0x65, 0x11,                          /* UNIT (SI Linear: Inches) */ \
        HID_REPORT_SIZE(8), \
        HID_REPORT_COUNT(1), \
        HID_INPUT(HID_DATA_VARIABLE_RELATIVE), \
    HID_END_COLLECTION
#endif

#endif /* ZMK_HID_OVERRIDE_H */
