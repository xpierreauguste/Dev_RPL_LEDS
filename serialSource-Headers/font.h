
#define font_width 5
#define font_height 4
// 5x5 pixel font 
const char Font[][5] PROGMEM = {
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}, // 32 <space>
{0b00000000, 0b00000000, 0b00010111, 0b00000000, 0b00000000}, // 33 !
{0b00000000, 0b00000011, 0b00000000, 0b00000011, 0b00000000}, // 34 "
{0b00001010, 0b00011111, 0b00001010, 0b00011111, 0b00001010}, // 35 #
{0b00010010, 0b00010101, 0b00011111, 0b00010101, 0b00001001}, // 36 $
{0b00010001, 0b00001000, 0b00000100, 0b00000010, 0b00010001}, // 37 %
{0b00001010, 0b00010101, 0b00001010, 0b00010000, 0b00000000}, // 38 &
{0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b00000000}, // 39 '
{0b00000000, 0b00000000, 0b00001110, 0b00010001, 0b00000000}, // 40 (
{0b00000000, 0b00010001, 0b00001110, 0b00000000, 0b00000000}, // 41 )
{0b00010001, 0b00001010, 0b00011111, 0b00001010, 0b00010001}, // 42 *
{0b00000100, 0b00000100, 0b00011111, 0b00000100, 0b00000100}, // 43 +
{0b00000000, 0b00010000, 0b00001000, 0b00000000, 0b00000000}, // 44 ,
{0b00000100, 0b00000100, 0b00000100, 0b00000100, 0b00000100}, // 45 -
{0b00000000, 0b00011000, 0b00011000, 0b00000000, 0b00000000}, // 46 .
{0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001}, // 47 /
{0b00001110, 0b00010001, 0b00010101, 0b00010001, 0b00001110}, // 48 0
{0x08, 0x18,0x08,0x08,0x1c}, // 49 1
{0x18,0x24,0x08,0x10,0x3c}, // 50 2
{0x38,0x04,0x18,0x04,0x38}, // 51 3
{0x24,0x24,0x1c,0x04,0x04}, // 52 4
{0b00010111, 0b00010101, 0b00010101, 0b00010101, 0b00001001}, // 53 5
{0b00001110, 0b00010101, 0b00010101, 0b00010101, 0b00001000}, // 54 6
{0b00000001, 0b00000001, 0b00011001, 0b00000101, 0b00000011}, // 55 7
{0b00001010, 0b00010101, 0b00010101, 0b00010101, 0b00001010}, // 56 8
{0b00000010, 0b00010101, 0b00010101, 0b00010101, 0b00001110}, // 57 9
{0b00000000, 0b00000000, 0b00001010, 0b00000000, 0b00000000}, // 58 :
{0b00000000, 0b00010000, 0b00001010, 0b00000000, 0b00000000}, // 59 ;
{0b00000000, 0b00000100, 0b00001010, 0b00010001, 0b00000000}, // 60 <
{0b00001010, 0b00001010, 0b00001010, 0b00001010, 0b00001010}, // 61 =
{0b00000000, 0b00010001, 0b00001010, 0b00000100, 0b00000000}, // 62 >
{0b00000010, 0b00000001, 0b00010101, 0b00000101, 0b00000010}, // 63 ?
{0b00011111, 0b00010001, 0b00010101, 0b00010101, 0b00010111}, // 64 @
{0x3c,0x24,0x3c,0x24,0x24}, // 65 A
// 0x18,0x24,0x3c,0x24,0x24
{0b00011111, 0b00010101, 0b00010101, 0b00010101, 0b00001010}, // 66 B
{0b00001110, 0b00010001, 0b00010001, 0b00010001, 0b00010001}, // 67 C
{0b00011111, 0b00010001, 0b00010001, 0b00010001, 0b00001110}, // 68 D
{0b00011111, 0b00010101, 0b00010101, 0b00010001, 0b00010001}, // 69 E
{0b00011111, 0b00000101, 0b00000101, 0b00000001, 0b00000001}, // 70 F
{0b00001110, 0b00010001, 0b00010101, 0b00010101, 0b00001101}, // 71 G
{0b00011111, 0b00000100, 0b00000100, 0b00000100, 0b00011111}, // 72 H
{0b00010001, 0b00010001, 0b00011111, 0b00010001, 0b00010001}, // 73 I
{0b00001000, 0b00010000, 0b00010000, 0b00010001, 0b00001111}, // 74 J
{0b00011111, 0b00000100, 0b00001010, 0b00010001, 0b00010001}, // 75 K
{0b00011111, 0b00010000, 0b00010000, 0b00010000, 0b00010000}, // 76 L
{0b00011111, 0b00000010, 0b00000100, 0b00000010, 0b00011111}, // 77 M
{0b00011111, 0b00000010, 0b00000100, 0b00001000, 0b00011111}, // 78 N
{0b00001110, 0b00010001, 0b00010001, 0b00010001, 0b00001110}, // 79 O
{0b00011111, 0b00000101, 0b00000101, 0b00000101, 0b00000010}, // 80 P
{0b00001110, 0b00010001, 0b00010001, 0b00001001, 0b00010110}, // 81 Q
{0b00011111, 0b00000101, 0b00000101, 0b00001101, 0b00010010}, // 82 R
{0b00010010, 0b00010101, 0b00010101, 0b00010101, 0b00001001}, // 83 S
{0b00000001, 0b00000001, 0b00011111, 0b00000001, 0b00000001}, // 84 T
{0b00001111, 0b00010000, 0b00010000, 0b00010000, 0b00001111}, // 85 U
{0b00000011, 0b00001100, 0b00010000, 0b00001100, 0b00000011}, // 86 V
{0b00000111, 0b00011000, 0b00000110, 0b00011000, 0b00000111}, // 87 W
{0b00010001, 0b00001010, 0b00000100, 0b00001010, 0b00010001}, // 88 X
{0b00000001, 0b00000010, 0b00011100, 0b00000010, 0b00000001}, // 89 Y
{0b00010001, 0b00011001, 0b00010101, 0b00010011, 0b00010001}, // 90 Z
{0b00000000, 0b00000000, 0b00011111, 0b00010001, 0b00010001}, // 91 [
{0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000}, // 92 
{0b00010001, 0b00010001, 0b00011111, 0b00000000, 0b00000000}, // 93 ]
{0b00000100, 0b00000010, 0b00000001, 0b00000010, 0b00000100}, // 94 ^
{0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000}, // 95 _
{0b00011111, 0b00010001, 0b00010001, 0b00010001, 0b00011111}}; // 96 <block>


/*
{0b00011110, 
 0b00000101, 
 0b00000101, 
 0b00000101, 
 0b00011110},

 .111.
 1...1
 11111
 1...1
 1...1
 .....
 .....
 .....


    .....
    .....
    .....
    .....
    .....
    .....
    .....
    .....

    .....  0x18,0x38,0x18,0x18,0x3c 1
    .....  0x08, 0x18,0x08,0x08,0x1a
    .....
    1..1.
    11111
    1....
    .....
    .....


    ..... 0x3c,0x24,0x7e,0x24,0x24
    1111.
    ..1.1
    ..1.1
    ..1.1
    ..1.1
    1111.
    .....

    .....  0x24,0x24,0x3c,0x24,0x18
    .....
    1111.
    ..1.1
    ..1.1
    1111.
    .....
    .....
    
*/