//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
// StyleAsCode exporter v1.2 - Style data exported as a values array            //
//                                                                              //
// USAGE: On init call: GuiLoadStyleJungle();                                   //
//                                                                              //
// more info and bugs-report:  github.com/raysan5/raygui                        //
// feedback and support:       ray[at]raylibtech.com                            //
//                                                                              //
// Copyright (c) 2020-2022 raylib technologies (@raylibtech)                    //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

#define JUNGLE_STYLE_PROPS_COUNT  16

// Custom style name: jungle
static const GuiStyleProp jungleStyleProps[JUNGLE_STYLE_PROPS_COUNT] = {
    { 0, 0, 0x60827dff },    // DEFAULT_BORDER_COLOR_NORMAL 
    { 0, 1, 0x2c3334ff },    // DEFAULT_BASE_COLOR_NORMAL 
    { 0, 2, 0x82a29fff },    // DEFAULT_TEXT_COLOR_NORMAL 
    { 0, 3, 0x5f9aa8ff },    // DEFAULT_BORDER_COLOR_FOCUSED 
    { 0, 4, 0x334e57ff },    // DEFAULT_BASE_COLOR_FOCUSED 
    { 0, 5, 0x6aa9b8ff },    // DEFAULT_TEXT_COLOR_FOCUSED 
    { 0, 6, 0xa9cb8dff },    // DEFAULT_BORDER_COLOR_PRESSED 
    { 0, 7, 0x3b6357ff },    // DEFAULT_BASE_COLOR_PRESSED 
    { 0, 8, 0x97af81ff },    // DEFAULT_TEXT_COLOR_PRESSED 
    { 0, 9, 0x5b6462ff },    // DEFAULT_BORDER_COLOR_DISABLED 
    { 0, 10, 0x2c3334ff },    // DEFAULT_BASE_COLOR_DISABLED 
    { 0, 11, 0x666b69ff },    // DEFAULT_TEXT_COLOR_DISABLED 
    { 0, 16, 0x0000000c },    // DEFAULT_TEXT_SIZE 
    { 0, 17, 0x00000000 },    // DEFAULT_TEXT_SPACING 
    { 0, 18, 0x638465ff },    // DEFAULT_LINE_COLOR 
    { 0, 19, 0x2b3a3aff },    // DEFAULT_BACKGROUND_COLOR 
};

// WARNING: This style uses a custom font:  (size: 12, spacing: 0)

#define JUNGLE_COMPRESSED_DATA_SIZE 1059

// Font image pixels data compressed (DEFLATE)
// NOTE: Original pixel data simplified to GRAYSCALE
static unsigned char jungleFontData[JUNGLE_COMPRESSED_DATA_SIZE] = { 0xed,
    0xdd, 0xe1, 0x6e, 0xdb, 0x20, 0x14, 0x06, 0x50, 0x84, 0xfa, 0xfe, 0xaf, 0xcc, 0xd4, 0x6d, 0xdd, 0xb4, 0x35, 0xc6, 0xdc,
    0x0b, 0xd8, 0x69, 0x7a, 0x7a, 0xd4, 0x3f, 0x71, 0xeb, 0xd8, 0x5c, 0x83, 0x53, 0xf1, 0x15, 0xb7, 0x02, 0x00, 0xf0, 0xc9,
    0xfb, 0xd7, 0xe3, 0xd7, 0x1e, 0x6d, 0x29, 0xbf, 0xb7, 0x8c, 0xef, 0xeb, 0xe3, 0xf5, 0x5f, 0x5b, 0xea, 0xe1, 0x4f, 0x3c,
    0xde, 0x63, 0x3d, 0x38, 0x86, 0xa3, 0xa3, 0x3e, 0x3e, 0xb2, 0x12, 0xda, 0x72, 0xbc, 0xff, 0xe3, 0xf6, 0x2a, 0x81, 0x73,
    0xf8, 0xf7, 0xab, 0x04, 0xce, 0xa5, 0xff, 0x7b, 0xbb, 0xeb, 0xdf, 0x6f, 0x83, 0xe3, 0x6d, 0xbf, 0xbe, 0xdf, 0x5b, 0xa2,
    0x06, 0xf6, 0x79, 0xfc, 0xf3, 0x25, 0x74, 0x05, 0xc6, 0xaf, 0x8c, 0x58, 0xeb, 0xf6, 0x7e, 0xfa, 0xec, 0x1c, 0x5a, 0xf0,
    0x08, 0x3e, 0x5e, 0xdf, 0x59, 0xff, 0xf2, 0xe7, 0x3d, 0xc6, 0xfb, 0xff, 0x59, 0x55, 0x5a, 0x7b, 0x7b, 0xd8, 0x12, 0xa5,
    0x5b, 0x9b, 0x9a, 0x78, 0xa7, 0x15, 0x57, 0x73, 0x59, 0xd4, 0xba, 0xb5, 0x7b, 0x0e, 0x2d, 0x51, 0xff, 0xdc, 0x15, 0xba,
    0x6a, 0x3f, 0xb9, 0xfe, 0xff, 0xee, 0xed, 0xe7, 0x15, 0xd0, 0xdf, 0xeb, 0xfc, 0x11, 0xaf, 0xea, 0xff, 0x65, 0x6b, 0xf5,
    0x67, 0xea, 0x7f, 0xc5, 0xf8, 0xdf, 0xff, 0xf9, 0x7e, 0x9b, 0x3d, 0xde, 0x5f, 0xfd, 0xdd, 0xff, 0xe3, 0x77, 0xcf, 0x15,
    0xf5, 0x8f, 0xdf, 0xff, 0xf7, 0x56, 0x7f, 0xc5, 0xf8, 0xff, 0x8c, 0x9f, 0x23, 0xcf, 0xee, 0xe3, 0x8f, 0xaf, 0x9d, 0xb6,
    0xbd, 0xff, 0xdf, 0xa1, 0x57, 0xfd, 0xb3, 0xcf, 0x7f, 0x6d, 0x62, 0x9c, 0xdd, 0xdd, 0xff, 0x33, 0xfb, 0xfa, 0x68, 0x89,
    0x96, 0xe8, 0x9f, 0x5f, 0xb5, 0xfe, 0xbd, 0xea, 0xb3, 0x62, 0xac, 0x89, 0xdc, 0xe5, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x5e, 0x73, 0xc6, 0xa4, 0x3f, 0xff, 0xbe, 0x72, 0x26, 0x72, 0xd7, 0xb6, 0xf1, 0xb4, 0x41, 0x24, 0xb9, 0x52, 0x13, 0x2d,
    0x76, 0x57, 0xbb, 0xec, 0x4a, 0xfb, 0x95, 0x70, 0x36, 0x63, 0xe4, 0x68, 0xb2, 0xef, 0x37, 0x53, 0xff, 0x1a, 0x9c, 0x7b,
    0xed, 0x27, 0xf4, 0x8e, 0xf2, 0x8c, 0xc7, 0x33, 0xd7, 0xb3, 0xe7, 0x17, 0xdd, 0x16, 0x1b, 0x01, 0xca, 0x25, 0xfd, 0x7f,
    0x2c, 0xc3, 0xb4, 0x27, 0xdd, 0xf8, 0x38, 0x67, 0xd6, 0x3b, 0xd6, 0xb7, 0x70, 0xa2, 0xf0, 0xef, 0x6c, 0xf3, 0xde, 0xeb,
    0x7b, 0x75, 0xea, 0x33, 0x9b, 0x28, 0xc9, 0x5c, 0x93, 0x99, 0x04, 0xeb, 0x8a, 0xf1, 0x7f, 0x4d, 0xff, 0xef, 0x5d, 0xa7,
    0xed, 0xbf, 0xef, 0x35, 0xe3, 0xf8, 0x5d, 0xf5, 0xdf, 0x31, 0x56, 0x97, 0x81, 0x51, 0x21, 0x7b, 0x2c, 0xb9, 0xfb, 0x7f,
    0x26, 0xa9, 0xd3, 0x4b, 0x2b, 0xe5, 0x3f, 0x4f, 0xdd, 0xd1, 0xff, 0x67, 0xfa, 0x78, 0x6e, 0xfc, 0xef, 0xd7, 0x7f, 0x5d,
    0xba, 0xad, 0xdd, 0xf2, 0x69, 0x7a, 0xa4, 0x8f, 0x3d, 0xd7, 0xfd, 0x9f, 0x95, 0x79, 0xc6, 0xfb, 0xfe, 0x9e, 0x52, 0x15,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf6, 0xe6, 0xf1, 0xae, 0xca, 0x94, 0xb4, 0xc1, 0x55, 0x7c, 0x8e, 0xf3, 0x5a, 0x57,
    0xa5, 0xf5, 0xae, 0x6f, 0xef, 0xd5, 0xb9, 0x8f, 0x15, 0x73, 0xd2, 0x99, 0x15, 0xcc, 0xe6, 0xb3, 0x88, 0xed, 0x29, 0x12,
    0x79, 0x3b, 0xda, 0xed, 0xce, 0xfa, 0x67, 0x8e, 0x27, 0x5f, 0xff, 0x96, 0x5c, 0x61, 0xf0, 0x6c, 0x65, 0x98, 0xe7, 0xaa,
    0x7f, 0x26, 0x75, 0x30, 0x53, 0xff, 0xf3, 0xb1, 0xaa, 0x74, 0xea, 0x11, 0x1f, 0xe3, 0xb3, 0xf5, 0x6f, 0xc9, 0x75, 0x1f,
    0xf7, 0xdc, 0xc5, 0xf6, 0xd4, 0x3f, 0xd3, 0x6e, 0xaf, 0x32, 0xfe, 0x9f, 0xef, 0xb3, 0x26, 0xc7, 0xff, 0x76, 0x3a, 0xaa,
    0xb4, 0xe5, 0x69, 0xd4, 0x78, 0x9f, 0x1a, 0x6d, 0x9f, 0xef, 0x5b, 0xff, 0xb2, 0xa5, 0xfe, 0x7b, 0xde, 0xf1, 0xeb, 0xdc,
    0xff, 0x33, 0xab, 0x57, 0xdf, 0x91, 0x73, 0x9b, 0xcb, 0x86, 0x9f, 0x6d, 0xbd, 0xa2, 0x65, 0xf6, 0x8d, 0xff, 0x52, 0x80,
    0x5f, 0x27, 0x25, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xc5, 0x1c, 0x45, 0x7e, 0xee, 0x6c, 0xc7, 0x0c, 0xe0, 0xe7,
    0xd7, 0xeb, 0xc0, 0x1c, 0xe6, 0xff, 0xaf, 0xd7, 0x83, 0xc4, 0x48, 0x0b, 0xae, 0xf9, 0x97, 0x7b, 0x1e, 0xef, 0xe8, 0x3a,
    0x68, 0xf9, 0x04, 0xe1, 0x8a, 0x79, 0xc0, 0xeb, 0xeb, 0x5f, 0x86, 0xe6, 0x63, 0x3f, 0x57, 0xb2, 0x26, 0x32, 0x43, 0x35,
    0xb8, 0xe2, 0x53, 0x6f, 0x85, 0xa8, 0x78, 0x9a, 0xe9, 0xbc, 0x15, 0x32, 0x6b, 0xdd, 0x9d, 0xed, 0x2d, 0xf7, 0x84, 0xe2,
    0x5e, 0x3a, 0xe6, 0x2c, 0xcb, 0x12, 0x3f, 0xf3, 0x1a, 0x3e, 0xb7, 0x3a, 0x30, 0x06, 0xec, 0xcf, 0x48, 0x97, 0x70, 0x7f,
    0x9c, 0xcb, 0xdd, 0xed, 0xaf, 0x7f, 0x19, 0xc8, 0xf8, 0xad, 0x4e, 0xa4, 0xb4, 0x93, 0xa7, 0xdf, 0x66, 0xae, 0x80, 0xdd,
    0xf5, 0x3f, 0x3b, 0xd7, 0x7c, 0x4a, 0xa8, 0x2c, 0xbd, 0x6e, 0x56, 0xd7, 0x7f, 0xe4, 0x3a, 0x5d, 0x7d, 0x05, 0x67, 0xae,
    0x80, 0x6b, 0xfa, 0x7f, 0x0b, 0xd7, 0xbf, 0x3f, 0x36, 0xac, 0x6f, 0xbd, 0x4c, 0x0a, 0x28, 0x37, 0xa2, 0xcc, 0xa6, 0xd5,
    0x32, 0x55, 0xac, 0xa9, 0x91, 0xe3, 0x8a, 0x4f, 0xd0, 0xb9, 0x67, 0x55, 0xaf, 0x4e, 0x6c, 0xe6, 0x5a, 0xe2, 0xfa, 0xfa,
    0xb7, 0xf4, 0x13, 0xbf, 0xeb, 0xd3, 0x3d, 0xfd, 0x3a, 0xd7, 0xeb, 0xf2, 0x89, 0xbd, 0xf5, 0xfd, 0xff, 0xf9, 0xfe, 0x1b,
    0xed, 0x8a, 0xdf, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x9e, 0x6b, 0x14, 0xc4, 0x57, 0xaa, 0x39, 0xff, 0x8d, 0xec,
    0xb3, 0xb3, 0xae, 0x7c, 0x76, 0xee, 0xae, 0xe7, 0xdb, 0xe5, 0xd7, 0x05, 0x6b, 0x5b, 0x9e, 0x00, 0xb7, 0x7e, 0xde, 0x6c,
    0x6e, 0x15, 0xb3, 0xb3, 0x16, 0xca, 0xae, 0xb8, 0x15, 0xcd, 0x60, 0xcc, 0xe4, 0x7a, 0xb2, 0x99, 0x8f, 0xf5, 0x39, 0xbc,
    0x35, 0xd9, 0xb6, 0x5c, 0xff, 0xcf, 0xe5, 0x42, 0x9e, 0xad, 0xfe, 0xe5, 0xa2, 0x7c, 0xde, 0x4c, 0xfd, 0x67, 0x9f, 0xfe,
    0x9c, 0x4f, 0x64, 0xc5, 0x5b, 0xf5, 0x15, 0xea, 0x3f, 0x96, 0xde, 0xcd, 0xe4, 0x08, 0x57, 0xe7, 0xf0, 0xee, 0xaa, 0x7f,
    0x4b, 0x3d, 0x3b, 0x77, 0xa6, 0xfe, 0x73, 0x79, 0xf9, 0xeb, 0xfa, 0x7f, 0xfe, 0x1d, 0xcb, 0x96, 0x27, 0xa3, 0xcf, 0xf6,
    0xd6, 0xd8, 0x4a, 0x8d, 0x77, 0x24, 0xb5, 0xd6, 0xe7, 0xe5, 0x76, 0x25, 0xbb, 0xee, 0x4d, 0x2f, 0xae, 0xca, 0xaf, 0xce,
    0xae, 0xfe, 0x7d, 0x47, 0xfd, 0x65, 0xc7, 0x5e, 0xfb, 0x2a, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x6e, 0xf3, 0x38,
    0xeb, 0x9e, 0x47, 0x15, 0x5d, 0xd5, 0xad, 0x85, 0x57, 0x68, 0x63, 0xd7, 0x0c, 0x70, 0xe9, 0x54, 0x69, 0x2e, 0xfd, 0x72,
    0xf4, 0x6a, 0xed, 0x26, 0x45, 0xb8, 0xbb, 0xfe, 0x35, 0xbc, 0x56, 0x5b, 0x7c, 0x45, 0x33, 0x9e, 0xb5, 0xfe, 0xf9, 0x14,
    0x97, 0x2b, 0xe0, 0x15, 0x92, 0x1c, 0x99, 0x9c, 0x9b, 0xfe, 0xff, 0x9a, 0xff, 0x07, 0xa2, 0xfe, 0x92, 0x5c, 0xea, 0xcf,
    0xca, 0xbf, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x29, 0x3f, 0x00 };

// Font characters rectangles data
static const Rectangle jungleFontRecs[95] = {
    { 4, 4, 5 , 12 },
    { 17, 4, 2 , 7 },
    { 27, 4, 5 , 3 },
    { 40, 4, 5 , 5 },
    { 53, 4, 6 , 7 },
    { 67, 4, 7 , 7 },
    { 82, 4, 5 , 7 },
    { 95, 4, 3 , 3 },
    { 106, 4, 4 , 8 },
    { 118, 4, 4 , 8 },
    { 130, 4, 5 , 5 },
    { 143, 4, 5 , 5 },
    { 156, 4, 2 , 3 },
    { 166, 4, 5 , 1 },
    { 179, 4, 2 , 2 },
    { 189, 4, 7 , 7 },
    { 204, 4, 7 , 6 },
    { 219, 4, 6 , 6 },
    { 233, 4, 6 , 6 },
    { 4, 24, 6 , 6 },
    { 18, 24, 6 , 6 },
    { 32, 24, 6 , 6 },
    { 46, 24, 6 , 6 },
    { 60, 24, 6 , 6 },
    { 74, 24, 6 , 6 },
    { 88, 24, 6 , 6 },
    { 102, 24, 2 , 5 },
    { 112, 24, 2 , 6 },
    { 122, 24, 3 , 5 },
    { 133, 24, 5 , 3 },
    { 146, 24, 3 , 5 },
    { 157, 24, 6 , 7 },
    { 171, 24, 7 , 7 },
    { 186, 24, 6 , 7 },
    { 200, 24, 6 , 7 },
    { 214, 24, 6 , 7 },
    { 228, 24, 6 , 7 },
    { 4, 44, 6 , 7 },
    { 18, 44, 6 , 7 },
    { 32, 44, 6 , 7 },
    { 46, 44, 6 , 7 },
    { 60, 44, 6 , 7 },
    { 74, 44, 6 , 7 },
    { 88, 44, 6 , 7 },
    { 102, 44, 6 , 7 },
    { 116, 44, 7 , 7 },
    { 131, 44, 6 , 7 },
    { 145, 44, 6 , 7 },
    { 159, 44, 6 , 7 },
    { 173, 44, 7 , 8 },
    { 188, 44, 6 , 7 },
    { 202, 44, 6 , 7 },
    { 216, 44, 6 , 7 },
    { 230, 44, 6 , 7 },
    { 4, 64, 6 , 7 },
    { 18, 64, 7 , 7 },
    { 33, 64, 6 , 7 },
    { 47, 64, 6 , 7 },
    { 61, 64, 6 , 7 },
    { 75, 64, 4 , 8 },
    { 87, 64, 7 , 7 },
    { 102, 64, 4 , 8 },
    { 114, 64, 4 , 2 },
    { 126, 64, 6 , 1 },
    { 140, 64, 2 , 2 },
    { 150, 64, 6 , 5 },
    { 164, 64, 6 , 7 },
    { 178, 64, 6 , 5 },
    { 192, 64, 6 , 7 },
    { 206, 64, 6 , 5 },
    { 220, 64, 6 , 7 },
    { 234, 64, 6 , 7 },
    { 4, 84, 6 , 7 },
    { 18, 84, 6 , 7 },
    { 32, 84, 5 , 8 },
    { 45, 84, 6 , 7 },
    { 59, 84, 6 , 7 },
    { 73, 84, 7 , 5 },
    { 88, 84, 6 , 5 },
    { 102, 84, 6 , 5 },
    { 116, 84, 6 , 7 },
    { 130, 84, 6 , 7 },
    { 144, 84, 6 , 5 },
    { 158, 84, 6 , 5 },
    { 172, 84, 6 , 6 },
    { 186, 84, 6 , 5 },
    { 200, 84, 6 , 5 },
    { 214, 84, 7 , 5 },
    { 229, 84, 6 , 5 },
    { 4, 104, 6 , 7 },
    { 18, 104, 6 , 5 },
    { 32, 104, 4 , 8 },
    { 44, 104, 2 , 8 },
    { 54, 104, 4 , 8 },
    { 66, 104, 5 , 2 },
};

// Font characters info data
// NOTE: No chars.image data provided
static const GlyphInfo jungleFontChars[95] = {
    { 32, 0, 9, 5, { 0 }},
    { 33, 0, 2, 3, { 0 }},
    { 34, 0, 2, 6, { 0 }},
    { 35, 0, 3, 6, { 0 }},
    { 36, 0, 2, 7, { 0 }},
    { 37, 0, 2, 8, { 0 }},
    { 38, 0, 2, 6, { 0 }},
    { 39, 0, 2, 4, { 0 }},
    { 40, 0, 2, 5, { 0 }},
    { 41, 0, 2, 5, { 0 }},
    { 42, 0, 2, 6, { 0 }},
    { 43, 0, 3, 6, { 0 }},
    { 44, 0, 7, 3, { 0 }},
    { 45, 0, 5, 6, { 0 }},
    { 46, 0, 7, 3, { 0 }},
    { 47, 0, 2, 8, { 0 }},
    { 48, 0, 3, 8, { 0 }},
    { 49, 0, 3, 7, { 0 }},
    { 50, 0, 3, 7, { 0 }},
    { 51, 0, 3, 7, { 0 }},
    { 52, 0, 3, 7, { 0 }},
    { 53, 0, 3, 7, { 0 }},
    { 54, 0, 3, 7, { 0 }},
    { 55, 0, 3, 7, { 0 }},
    { 56, 0, 3, 7, { 0 }},
    { 57, 0, 3, 7, { 0 }},
    { 58, 0, 4, 3, { 0 }},
    { 59, 0, 4, 3, { 0 }},
    { 60, 0, 3, 4, { 0 }},
    { 61, 0, 4, 6, { 0 }},
    { 62, 0, 3, 4, { 0 }},
    { 63, 0, 2, 7, { 0 }},
    { 64, 0, 2, 8, { 0 }},
    { 65, 0, 2, 7, { 0 }},
    { 66, 0, 2, 7, { 0 }},
    { 67, 0, 2, 7, { 0 }},
    { 68, 0, 2, 7, { 0 }},
    { 69, 0, 2, 7, { 0 }},
    { 70, 0, 2, 7, { 0 }},
    { 71, 0, 2, 7, { 0 }},
    { 72, 0, 2, 7, { 0 }},
    { 73, 0, 2, 7, { 0 }},
    { 74, 0, 2, 7, { 0 }},
    { 75, 0, 2, 7, { 0 }},
    { 76, 0, 2, 7, { 0 }},
    { 77, 0, 2, 8, { 0 }},
    { 78, 0, 2, 7, { 0 }},
    { 79, 0, 2, 7, { 0 }},
    { 80, 0, 2, 7, { 0 }},
    { 81, 0, 2, 7, { 0 }},
    { 82, 0, 2, 7, { 0 }},
    { 83, 0, 2, 7, { 0 }},
    { 84, 0, 2, 7, { 0 }},
    { 85, 0, 2, 7, { 0 }},
    { 86, 0, 2, 7, { 0 }},
    { 87, 0, 2, 8, { 0 }},
    { 88, 0, 2, 7, { 0 }},
    { 89, 0, 2, 7, { 0 }},
    { 90, 0, 2, 7, { 0 }},
    { 91, 0, 2, 5, { 0 }},
    { 92, 0, 2, 8, { 0 }},
    { 93, 0, 2, 5, { 0 }},
    { 94, 0, -1, 5, { 0 }},
    { 95, 0, 10, 7, { 0 }},
    { 96, 0, -1, 3, { 0 }},
    { 97, 0, 4, 7, { 0 }},
    { 98, 0, 2, 7, { 0 }},
    { 99, 0, 4, 7, { 0 }},
    { 100, 0, 2, 7, { 0 }},
    { 101, 0, 4, 7, { 0 }},
    { 102, 0, 2, 7, { 0 }},
    { 103, 0, 4, 7, { 0 }},
    { 104, 0, 2, 7, { 0 }},
    { 105, 0, 2, 7, { 0 }},
    { 106, 0, 2, 6, { 0 }},
    { 107, 0, 2, 7, { 0 }},
    { 108, 0, 2, 7, { 0 }},
    { 109, 0, 4, 8, { 0 }},
    { 110, 0, 4, 7, { 0 }},
    { 111, 0, 4, 7, { 0 }},
    { 112, 0, 4, 7, { 0 }},
    { 113, 0, 4, 7, { 0 }},
    { 114, 0, 4, 7, { 0 }},
    { 115, 0, 4, 7, { 0 }},
    { 116, 0, 3, 7, { 0 }},
    { 117, 0, 4, 7, { 0 }},
    { 118, 0, 4, 7, { 0 }},
    { 119, 0, 4, 8, { 0 }},
    { 120, 0, 4, 7, { 0 }},
    { 121, 0, 4, 7, { 0 }},
    { 122, 0, 4, 7, { 0 }},
    { 123, 0, 2, 5, { 0 }},
    { 124, 0, 2, 3, { 0 }},
    { 125, 0, 2, 5, { 0 }},
    { 126, 0, -1, 6, { 0 }},
};

// Style loading function: jungle
static void GuiLoadStyleJungle(void)
{
    // Load style properties provided
    // NOTE: Default properties are propagated
    for (int i = 0; i < JUNGLE_STYLE_PROPS_COUNT; i++)
    {
        GuiSetStyle(jungleStyleProps[i].controlId, jungleStyleProps[i].propertyId, jungleStyleProps[i].propertyValue);
    }

    // Custom font loading
    // NOTE: Compressed font image data (DEFLATE), it requires DecompressData() function
    int jungleFontDataSize = 0;
    unsigned char *data = DecompressData(jungleFontData, JUNGLE_COMPRESSED_DATA_SIZE, &jungleFontDataSize);
    Image imFont = { data, 256, 256, 1, 2 };

    Font font = { 0 };
    font.baseSize = 12;
    font.glyphCount = 95;

    // Load texture from image
    font.texture = LoadTextureFromImage(imFont);
    UnloadImage(imFont);  // Uncompressed data can be unloaded from memory

    // Copy char recs data from global fontRecs
    // NOTE: Required to avoid issues if trying to free font
    font.recs = (Rectangle *)malloc(font.glyphCount*sizeof(Rectangle));
    memcpy(font.recs, jungleFontRecs, font.glyphCount*sizeof(Rectangle));

    // Copy font char info data from global fontChars
    // NOTE: Required to avoid issues if trying to free font
    font.glyphs = (GlyphInfo *)malloc(font.glyphCount*sizeof(GlyphInfo));
    memcpy(font.glyphs, jungleFontChars, font.glyphCount*sizeof(GlyphInfo));

    GuiSetFont(font);

    // Setup a white rectangle on the font to be used on shapes drawing,
    // this way we make sure all gui can be drawn on a single pass because no texture change is required
    // NOTE: Setting up this rectangle is a manual process (for the moment)
    Rectangle whiteChar = { 27, 4, 2, 2 };
    SetShapesTexture(font.texture, whiteChar);
}
