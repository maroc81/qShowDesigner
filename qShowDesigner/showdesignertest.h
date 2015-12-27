#ifndef SHOWDESIGNERTEST_H
#define SHOWDESIGNERTEST_H

//static const quint8 testdata[] = {0x55,0x25,0x05,char(0xa5),0x01,char(0xa5),0x01,char(0xa5),0x04,char(0xff),,char(0xa5),0x0b,0x02,char(0xa5),0x02,0x02,0x00,0x06,0x00,char(0xa5),0x0c,0x02,0x00,0x00,0x01,char(0xa5),0x0c,0x02,0x00,0x01,0x00,char(0xa5),0x0c,0x02,0x00,0x02,0x00,char(0xa5),0x0c,0x02,0x00,0x03,0x00,char(0xa5),0x0c,0x02,0x00,0x04,0x00,char(0xa5),0x0c,0x02,0x00,0x05,0x00,char(0xa5),0x0c,0x02,0x00,0x06,0x00,char(0xa5),0x0c,0x02,0x00,0x07,0x00,char(0xa5),0x0c,0x02,0x00,0x08,0x00,char(0xa5),0x0c,0x02,0x00,0x09,0x00,char(0xa5),0x0c,0x02,0x00,0x0a,0x00,char(0xa5),0x0c,0x02,0x00,0x0b,0x00,char(0xa5),0x0c,0x02,0x00,0x0c,0x00,char(0xa5),0x0c,0x02,0x00,0x0d,0x00,char(0xa5),0x0c,0x02,0x00,0x0e,0x00,char(0xa5),0x0c,0x02,0x00,0x0f,0x00,char(0xa5),0x0c,0x02,0x00,0x10,0x00,char(0xa5),0x0c,0x02,0x00,0x11,0x00,char(0xa5),0x0c,0x02,0x00,0x12,0x00,char(0xa5),0x0c,0x02,0x00,0x13,0x00,char(0xa5),0x0c,0x02,0x00,0x14,0x00,char(0xa5),0x0c,0x02,0x00,0x15,0x00,char(0xa5),0x0c,0x02,0x00,0x16,0x00,char(0xa5),0x0c,0x02,0x00,0x17,0x00,char(0xa5),0x0c,0x02,0x00,0x18,0x00,char(0xa5),0x0c,0x02,0x00,0x19,0x00,char(0xa5),0x0c,0x02,0x00,0x1a,0x00,char(0xa5),0x0c,0x02,0x00,0x1b,0x00,char(0xa5),0x0c,0x02,0x00,0x1c,0x00,char(0xa5),0x0c,0x02,0x00,0x1d,0x00,char(0xa5),0x0c,0x02,0x00,0x1e,0x00,char(0xa5),0x0c,0x02,0x00,0x1f,0x00,char(0xa5),0x0c,0x02,0x00,0x20,0x00,char(0xa5),0x0c,0x02,0x00,0x21,0x00,char(0xa5),0x0c,0x02,0x00,0x22,0x00,char(0xa5),0x0c,0x02,0x00,0x23,0x00,char(0xa5),0x0c,0x02,0x00,0x24,0x00,char(0xa5),0x0c,0x02,0x00,0x25,0x00,char(0xa5),0x0c,0x02,0x00,0x26,0x00,char(0xa5),0x0c,0x02,0x00,0x27,0x00,char(0xa5),0x0c,0x02,0x00,0x28,0x00,char(0xa5),0x0c,0x02,0x00,0x29,0x00,char(0xa5),0x0c,0x02,0x00,0x2a,0x04,char(0xa5),0x0c,0x02,0x00,0x2b,0x00,char(0xa5),0x0c,0x02,0x00,0x2c,0x00,char(0xa5),0x0c,0x02,0x00,0x2d,0x00,char(0xa5),0x0c,0x02,0x00,0x2e,0x00,char(0xa5),0x0c,0x02,0x00,0x2f,0x00,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x14,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x19,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x1e,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x23,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x28,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x2d,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x32,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x37,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x3c,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x41,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x46,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x4b,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x50,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x55,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x50,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x4b,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x46,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x41,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x3c,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x37,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x32,char(0xa5),0x08,0x2a,0x02,0x00,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x00,char(0xa5),0x02,char(0xa5),0x02,0x02,0x00,0x06,0x00,char(0xa5),0x03,0x06,0x00,char(0xa5),0x03,0x05,0x03,0x06,0x00,0x00,0x30,0x10,0x48,0x6f,0x75,0x73,0x65,0x20,0x4c,0x69,0x67,0x68,0x74,0x73,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x64,0x20,0x20,0x20,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x72,0x20,0x46,0x6c,0x6f,0x64,0x53,0x74,0x61,0x67,0x65,0x20,0x53,0x69,0x64,0x65,0x73,0x20,0x46,0x6c,0x6f,0x64,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x53,0x70,0x6f,0x74,0x20,0x20,0x20,0x20,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x72,0x20,0x53,0x70,0x6f,0x74,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4f,0x70,0x74,0x69,0x20,0x54,0x72,0x69,0x20,0x50,0x61,0x72,0x20,0x20,0x20,0x20,0x52,0x69,0x67,0x68,0x74,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x4c,0x45,0x44,0x20,0x4c,0x65,0x66,0x74,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x4c,0x45,0x44,0x20,0x20,0x52,0x69,0x67,0x68,0x74,0x2f,0x4c,0x65,0x66,0x74,0x20,0x57,0x61,0x6c,0x6c,0x73,0x4c,0x65,0x66,0x74,0x20,0x50,0x61,0x6e,0x65,0x6c,0x20,0x4c,0x45,0x44,0x20,0x20,0x52,0x74,0x2f,0x4c,0x66,0x20,0x53,0x6d,0x61,0x6c,0x6c,0x20,0x50,0x6e,0x6c,0x73,char(0xa5),0x0e,0x00,char(0xa5),0x02,0x02,0x00,0x00,0x03,char(0xa5),0x03,0x00,0x03,char(0xa5),0x03,0x05,0x03,0x00,0x03,0x00,0x30,0x10,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,char(0xa5),0x0e,0x04,char(0xa5),0x02,0x02,0x00,0x06,0x00,char(0xa5),0x03,0x06,0x00,char(0xa5),0x03,0x05,0x03,0x06,0x00,0x00,0x30,0x10,0x48,0x6f,0x75,0x73,0x65,0x20,0x4c,0x69,0x67,0x68,0x74,0x73,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x64,0x20,0x20,0x20,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x72,0x20,0x46,0x6c,0x6f,0x64,0x53,0x74,0x61,0x67,0x65,0x20,0x53,0x69,0x64,0x65,0x73,0x20,0x46,0x6c,0x6f,0x64,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x53,0x70,0x6f,0x74,0x20,0x20,0x20,0x20,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x72,0x20,0x53,0x70,0x6f,0x74,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4f,0x70,0x74,0x69,0x20,0x54,0x72,0x69,0x20,0x50,0x61,0x72,0x20,0x20,0x20,0x20,0x52,0x69,0x67,0x68,0x74,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x4c,0x45,0x44,0x20,0x4c,0x65,0x66,0x74,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x4c,0x45,0x44,0x20,0x20,0x52,0x69,0x67,0x68,0x74,0x2f,0x4c,0x65,0x66,0x74,0x20,0x57,0x61,0x6c,0x6c,0x73,0x4c,0x65,0x66,0x74,0x20,0x50,0x61,0x6e,0x65,0x6c,0x20,0x4c,0x45,0x44,0x20,0x20,0x52,0x74,0x2f,0x4c,0x66,0x20,0x53,0x6d,0x61,0x6c,0x6c,0x20,0x50,0x6e,0x6c,0x73,char(0xa5),0x0e,0x00,char(0xa5),0x02,0x02,0x00,0x00,0x03,char(0xa5),0x03,0x00,0x03,char(0xa5),0x03,0x05,0x03,0x00,0x03,0x00,0x30,0x10,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x35,0x2e,0x4e,0x41,0x4d,0x45,0x44,0x20,0x53,0x43,0x45,0x4e,0x45,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,char(0xa5),0x0f,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x90,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x86,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x7c,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x72,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x68,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x99,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x98,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x1d,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x63,0x00,0x46,char(0xa5),0x09,0x03,0x00,0x64,0x00,0x92,char(0xa5),0x09,0x03,0x00,0x65,0x00,0x83,char(0xa5),0x09,0x03,0x00,0x6d,0x00,0x46,char(0xa5),0x09,0x03,0x00,0x6e,0x00,0x92,char(0xa5),0x09,0x03,0x00,0x6f,0x00,0x83,char(0xa5),0x09,0x03,0x00,0x77,0x00,0x46,char(0xa5),0x09,0x03,0x00,0x78,0x00,0x92,char(0xa5),0x09,0x03,0x00,0x79,0x00,0x83,char(0xa5),0x09,0x03,0x00,0x95,0x00,0x46,char(0xa5),0x09,0x03,0x00,0x96,0x00,0x92,char(0xa5),0x09,0x03,0x00,0x97,0x00,0x83,char(0xa5),0x09,0x03,0x00,0x9a,0x00,char(0xff),char(0xa5),0x0f,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x1d,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x0e,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x0f,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x10,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x11,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x12,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x13,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x14,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x1f,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x9a,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x8b,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x8c,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x8d,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x8e,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x8f,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x90,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x81,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x82,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x83,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x84,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x85,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x86,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x77,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x78,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x79,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x7a,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x7b,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x7c,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x6d,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x6e,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x6f,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x70,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x71,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x72,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x63,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x64,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x65,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x66,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x67,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x68,0x00,0x00,char(0xa5),0x0f,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x90,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x86,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x7c,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x72,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x68,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x99,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x98,0x00,0x00,char(0xa5),0x09,0x03,0x00,0x1d,0x00,char(0xff),char(0xa5),0x09,0x03,0x00,0x63,0x00,0x46,char(0xa5),0x09,0x03,0x00,0x64,0x00,0x92,char(0xa5),0x09,0x03,0x00,0x65,0x00,0x83,char(0xa5),0x09,0x03,0x00,0x6d,0x00,0x46,char(0xa5),0x09,0x03,0x00,0x6e,0x00,0x92,char(0xa5),0x09,0x03,0x00,0x6f,0x00,0x83,char(0xa5),0x09,0x03,0x00,0x77,0x00,0x46,char(0xa5),0x09,0x03,0x00,0x78,0x00,0x92,char(0xa5),0x09,0x03,0x00,0x79,0x00,0x83,char(0xa5),0x09,0x03,0x00,0x9a,0x00,char(0xff),char(0xa5),0x0e,0x04,char(0xa5),0x02,0x02,0x00,0x06,0x00,char(0xa5),0x03,0x06,0x00,char(0xa5),0x03,0x05,0x03,0x06,0x00,0x00,0x30,0x10,0x48,0x6f,0x75,0x73,0x65,0x20,0x4c,0x69,0x67,0x68,0x74,0x73,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x64,0x20,0x20,0x20,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x72,0x20,0x46,0x6c,0x6f,0x64,0x53,0x74,0x61,0x67,0x65,0x20,0x53,0x69,0x64,0x65,0x73,0x20,0x46,0x6c,0x6f,0x64,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x53,0x70,0x6f,0x74,0x20,0x20,0x20,0x20,0x20,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x72,0x20,0x53,0x70,0x6f,0x74,0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x75,0x6e,0x75,0x73,0x65,0x64,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4f,0x70,0x74,0x69,0x20,0x54,0x72,0x69,0x20,0x50,0x61,0x72,0x20,0x20,0x20,0x20,0x52,0x69,0x67,0x68,0x74,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x4c,0x45,0x44,0x20,0x4c,0x65,0x66,0x74,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x4c,0x45,0x44,0x20,0x20,0x52,0x69,0x67,0x68,0x74,0x2f,0x4c,0x65,0x66,0x74,0x20,0x57,0x61,0x6c,0x6c,0x73,0x4c,0x65,0x66,0x74,0x20,0x50,0x61,0x6e,0x65,0x6c,0x20,0x4c,0x45,0x44,0x20,0x20,0x52,0x74,0x2f,0x4c,0x66,0x20,0x53,0x6d,0x61,0x6c,0x6c,0x20,0x50,0x6e,0x6c,0x73,char(0xa5),0x0f,0x00,0x00,char(0xa5),0x0c,0x02,0x00,0x00,0x00};

const char sdConnect[] = {0x55,0x25,0x05,char(0xa5),0x01,char(0xa5),0x01};

const char sdTestFixtureResp[] = {char(0xa5),0x04,0x3e,0x00,0x00,0x05,0x00,0x01,0x01,0x1d,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x48,0x6f,0x75,0x73,0x65,0x20,0x4c,0x69,0x67,0x68,0x74,0x73,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x02,0x00,0x01,0x00,char(0xa5),0x04,0x02,0x00,0x02,0x00,char(0xa5),0x04,0x02,0x00,0x03,0x00,char(0xa5),0x04,0x02,0x00,0x04,0x00,char(0xa5),0x04,0x02,0x00,0x05,0x00,char(0xa5),0x04,0x02,0x00,0x06,0x00,char(0xa5),0x04,0x02,0x00,0x07,0x00,char(0xa5),0x04,0x02,0x00,0x08,0x00,char(0xa5),0x04,0x02,0x00,0x09,0x00,char(0xa5),0x04,0x02,0x00,0x0a,0x00,char(0xa5),0x04,0x02,0x00,0x0b,0x00,char(0xa5),0x04,0x02,0x00,0x0c,0x00,char(0xa5),0x04,0x02,0x00,0x0d,0x00,char(0xa5),0x04,0x02,0x00,0x0e,0x00,char(0xa5),0x04,0x02,0x00,0x0f,0x00,char(0xa5),0x04,0x02,0x00,0x10,0x00,char(0xa5),0x04,0x02,0x00,0x11,0x00,char(0xa5),0x04,0x02,0x00,0x12,0x00,char(0xa5),0x04,0x02,0x00,0x13,0x00,char(0xa5),0x04,0x02,0x00,0x14,0x00,char(0xa5),0x04,0x02,0x00,0x15,0x00,char(0xa5),0x04,0x02,0x00,0x16,0x00,char(0xa5),0x04,0x02,0x00,0x17,0x00,char(0xa5),0x04,0x3e,0x00,0x18,0x05,0x00,0x01,0x01,0x0e,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x3e,0x00,0x19,0x05,0x00,0x01,0x01,0x0f,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x64,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x3e,0x00,0x1a,0x05,0x00,0x01,0x01,0x10,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x72,0x20,0x46,0x6c,0x6f,0x64,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x3e,0x00,0x1b,0x05,0x00,0x01,0x01,0x11,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x53,0x74,0x61,0x67,0x65,0x20,0x53,0x69,0x64,0x65,0x73,0x20,0x46,0x6c,0x6f,0x64,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x3e,0x00,0x1c,0x05,0x00,0x01,0x01,0x12,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x3e,0x00,0x1d,0x05,0x00,0x01,0x01,0x13,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x53,0x74,0x61,0x67,0x65,0x20,0x53,0x70,0x6f,0x74,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x3e,0x00,0x1e,0x05,0x00,0x01,0x01,0x14,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x53,0x74,0x61,0x67,0x65,0x20,0x46,0x6c,0x6f,0x6f,0x72,0x20,0x53,0x70,0x6f,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x3e,0x00,0x1f,0x05,0x00,0x01,0x01,0x1f,0x00,0x00,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x47,0x65,0x6e,0x65,0x72,0x69,0x63,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x04,0x02,0x00,0x20,0x00,char(0xa5),0x04,0x02,0x00,0x21,0x00,char(0xa5),0x04,0x02,0x00,0x22,0x00,char(0xa5),0x04,0x02,0x00,0x23,0x00,char(0xa5),0x04,0x02,0x00,0x24,0x00,char(0xa5),0x04,0x02,0x00,0x25,0x00,char(0xa5),0x04,0x02,0x00,0x26,0x00,char(0xa5),0x04,0x02,0x00,0x27,0x00,char(0xa5),0x04,0x02,0x00,0x28,0x00,char(0xa5),0x04,0x02,0x00,0x29,0x00,char(0xa5),0x04,0x6e,0x00,0x2a,char(0xff),0x00,0x06,0x01,0x95,0x00,0x05,0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x4f,0x70,0x74,0x69,0x20,0x54,0x72,0x69,0x20,0x50,0x61,0x72,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x06,0x20,0x20,0x20,0x52,0x65,0x64,0x20,0x20,0x20,0x20,0x47,0x72,0x65,0x65,0x6e,0x20,0x20,0x20,0x42,0x6c,0x75,0x65,0x20,0x20,0x20,0x20,0x4d,0x61,0x63,0x72,0x6f,0x20,0x20,0x20,0x53,0x70,0x65,0x65,0x64,0x20,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,char(0xa5),0x04,0x6e,0x00,0x2b,0x03,0x00,0x06,0x01,0x8b,0x00,char(0xff),0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x52,0x69,0x67,0x68,0x74,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x4c,0x45,0x44,0x20,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x06,0x20,0x52,0x61,0x69,0x6e,0x62,0x6f,0x77,0x20,0x20,0x20,0x52,0x65,0x64,0x20,0x20,0x20,0x20,0x47,0x72,0x65,0x65,0x6e,0x20,0x20,0x20,0x42,0x6c,0x75,0x65,0x20,0x20,0x20,0x53,0x74,0x72,0x6f,0x62,0x65,0x20,0x50,0x72,0x6f,0x67,0x72,0x61,0x6d,0x73,char(0xa5),0x04,0x6e,0x00,0x2c,0x03,0x00,0x06,0x01,0x81,0x00,char(0xff),0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x4c,0x65,0x66,0x74,0x20,0x53,0x74,0x61,0x67,0x65,0x20,0x4c,0x45,0x44,0x20,0x20,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x06,0x20,0x52,0x61,0x69,0x6e,0x62,0x6f,0x77,0x20,0x20,0x20,0x52,0x65,0x64,0x20,0x20,0x20,0x20,0x47,0x72,0x65,0x65,0x6e,0x20,0x20,0x20,0x42,0x6c,0x75,0x65,0x20,0x20,0x20,0x53,0x74,0x72,0x6f,0x62,0x65,0x20,0x50,0x72,0x6f,0x67,0x72,0x61,0x6d,0x73,char(0xa5),0x04,0x6e,0x00,0x2d,0x03,0x00,0x06,0x01,0x77,0x00,char(0xff),0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x52,0x69,0x67,0x68,0x74,0x2f,0x4c,0x65,0x66,0x74,0x20,0x57,0x61,0x6c,0x6c,0x73,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x06,0x20,0x52,0x61,0x69,0x6e,0x62,0x6f,0x77,0x20,0x20,0x20,0x52,0x65,0x64,0x20,0x20,0x20,0x20,0x47,0x72,0x65,0x65,0x6e,0x20,0x20,0x20,0x42,0x6c,0x75,0x65,0x20,0x20,0x20,0x53,0x74,0x72,0x6f,0x62,0x65,0x20,0x50,0x72,0x6f,0x67,0x72,0x61,0x6d,0x73,char(0xa5),0x04,0x6e,0x00,0x2e,0x03,0x00,0x06,0x01,0x6d,0x00,char(0xff),0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x4c,0x65,0x66,0x74,0x20,0x50,0x61,0x6e,0x65,0x6c,0x20,0x4c,0x45,0x44,0x20,0x20,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x06,0x20,0x52,0x61,0x69,0x6e,0x62,0x6f,0x77,0x20,0x20,0x20,0x52,0x65,0x64,0x20,0x20,0x20,0x20,0x47,0x72,0x65,0x65,0x6e,0x20,0x20,0x20,0x42,0x6c,0x75,0x65,0x20,0x20,0x20,0x53,0x74,0x72,0x6f,0x62,0x65,0x20,0x50,0x72,0x6f,0x67,0x72,0x61,0x6d,0x73,char(0xa5),0x04,0x6e,0x00,0x2f,0x03,0x00,0x06,0x01,0x63,0x00,char(0xff),0x00,char(0xff),char(0xff),char(0xff),char(0xff),0x52,0x74,0x2f,0x4c,0x66,0x20,0x53,0x6d,0x61,0x6c,0x6c,0x20,0x50,0x6e,0x6c,0x73,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x06,0x20,0x52,0x61,0x69,0x6e,0x62,0x6f,0x77,0x20,0x20,0x20,0x52,0x65,0x64,0x20,0x20,0x20,0x20,0x47,0x72,0x65,0x65,0x6e,0x20,0x20,0x20,0x42,0x6c,0x75,0x65,0x20,0x20,0x20,0x53,0x74,0x72,0x6f,0x62,0x65,0x20,0x50,0x72,0x6f,0x67,0x72,0x61,0x6d,0x73,char(0xa5),0x07,0xfa,0x00,0x00,0x1d,0xb7,0x00,0x01,0x4f,0x70,0x74,0x69,0x20,0x54,0x72,0x69,0x20,0x50,0x61,0x72,0x20,0x20,0x20,0x20,0xdb,0x00,0x4f,0x50,0x54,0x49,0x54,0x52,0x49,0x50,0x06,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x52,0x65,0x64,0x20,0x20,0x20,0x20,0x47,0x72,0x65,0x65,0x6e,0x20,0x20,0x20,0x42,0x6c,0x75,0x65,0x20,0x20,0x20,0x20,0x4d,0x61,0x63,0x72,0x6f,0x20,0x20,0x20,0x53,0x70,0x65,0x65,0x64,0x20,0x20,0x44,0x69,0x6d,0x6d,0x65,0x72,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x00,0x00,char(0xc5),char(0xa5),0x08,0x03,0x00,0x18,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x19,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x1a,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x1b,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x1c,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x1d,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x1e,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x1f,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x2a,0x00,0x16,char(0xa5),0x08,0x03,0x00,0x2a,0x01,0x34,char(0xa5),0x08,0x03,0x00,0x2a,0x02,0x13,char(0xa5),0x08,0x03,0x00,0x2a,0x03,0x00,char(0xa5),0x08,0x03,0x00,0x2a,0x04,0x00,char(0xa5),0x08,0x03,0x00,0x2a,0x05,0xb2,char(0xa5),0x08,0x03,0x00,0x2b,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x2b,0x01,0x00,char(0xa5),0x08,0x03,0x00,0x2b,0x02,0x00,char(0xa5),0x08,0x03,0x00,0x2b,0x03,0x00,char(0xa5),0x08,0x03,0x00,0x2b,0x04,0x00,char(0xa5),0x08,0x03,0x00,0x2b,0x05,char(0xff),char(0xa5),0x08,0x03,0x00,0x2c,0x00,0x00,char(0xa5),0x08,0x03,0x00,0x2c,0x01,0x00,char(0xa5),0x08,0x03,0x00,0x2c,0x02,0x00,char(0xa5),0x08,0x03,0x00,0x2c,0x03,0x00,char(0xa5),0x08,0x03,0x00,0x2c,0x04,0x00,char(0xa5),0x08,0x03,0x00,0x2c,0x05,char(0xff),char(0xa5),0x08,0x03,0x00,0x2d,0x00,0x16,char(0xa5),0x08,0x03,0x00,0x2d,0x01,0x2c,char(0xa5),0x08,0x03,0x00,0x2d,0x02,0x13,char(0xa5),0x08,0x03,0x00,0x2d,0x03,0x00,char(0xa5),0x08,0x03,0x00,0x2d,0x04,0x00,char(0xa5),0x08,0x03,0x00,0x2d,0x05,char(0xc6),char(0xa5),0x08,0x03,0x00,0x2e,0x00,0x16,char(0xa5),0x08,0x03,0x00,0x2e,0x01,0x2c,char(0xa5),0x08,0x03,0x00,0x2e,0x02,0x13,char(0xa5),0x08,0x03,0x00,0x2e,0x03,0x00,char(0xa5),0x08,0x03,0x00,0x2e,0x04,0x00,char(0xa5),0x08,0x03,0x00,0x2e,0x05,char(0xc6),char(0xa5),0x08,0x03,0x00,0x2f,0x00,0x25,char(0xa5),0x08,0x03,0x00,0x2f,0x01,0x22,char(0xa5),0x08,0x03,0x00,0x2f,0x02,0x13,char(0xa5),0x08,0x03,0x00,0x2f,0x03,0x00,char(0xa5),0x08,0x03,0x00,0x2f,0x04,0x00,char(0xa5),0x08,0x03,0x00,0x2f,0x05,0x52,char(0xa5),0x0c,0x02,0x00,0x00,0x01,char(0xa5),0x0c,0x02,0x00,0x01,0x00,char(0xa5),0x0c,0x02,0x00,0x02,0x00,char(0xa5),0x0c,0x02,0x00,0x03,0x00,char(0xa5),0x0c,0x02,0x00,0x04,0x00,char(0xa5),0x0c,0x02,0x00,0x05,0x00,char(0xa5),0x0c,0x02,0x00,0x06,0x00,char(0xa5),0x0c,0x02,0x00,0x07,0x00,char(0xa5),0x0c,0x02,0x00,0x08,0x00,char(0xa5),0x0c,0x02,0x00,0x09,0x00,char(0xa5),0x0c,0x02,0x00,0x0a,0x00,char(0xa5),0x0c,0x02,0x00,0x0b,0x00,char(0xa5),0x0c,0x02,0x00,0x0c,0x00,char(0xa5),0x0c,0x02,0x00,0x0d,0x00,char(0xa5),0x0c,0x02,0x00,0x0e,0x00,char(0xa5),0x0c,0x02,0x00,0x0f,0x00,char(0xa5),0x0c,0x02,0x00,0x10,0x00,char(0xa5),0x0c,0x02,0x00,0x11,0x00,char(0xa5),0x0c,0x02,0x00,0x12,0x00,char(0xa5),0x0c,0x02,0x00,0x13,0x00,char(0xa5),0x0c,0x02,0x00,0x14,0x00,char(0xa5),0x0c,0x02,0x00,0x15,0x00,char(0xa5),0x0c,0x02,0x00,0x16,0x00,char(0xa5),0x0c,0x02,0x00,0x17,0x00,char(0xa5),0x0c,0x02,0x00,0x18,0x00,char(0xa5),0x0c,0x02,0x00,0x19,0x00,char(0xa5),0x0c,0x02,0x00,0x1a,0x00,char(0xa5),0x0c,0x02,0x00,0x1b,0x00,char(0xa5),0x0c,0x02,0x00,0x1c,0x00,char(0xa5),0x0c,0x02,0x00,0x1d,0x00,char(0xa5),0x0c,0x02,0x00,0x1e,0x00,char(0xa5),0x0c,0x02,0x00,0x1f,0x00,char(0xa5),0x0c,0x02,0x00,0x20,0x00,char(0xa5),0x0c,0x02,0x00,0x21,0x00,char(0xa5),0x0c,0x02,0x00,0x22,0x00,char(0xa5),0x0c,0x02,0x00,0x23,0x00,char(0xa5),0x0c,0x02,0x00,0x24,0x00,char(0xa5),0x0c,0x02,0x00,0x25,0x00,char(0xa5),0x0c,0x02,0x00,0x26,0x00,char(0xa5),0x0c,0x02,0x00,0x27,0x00,char(0xa5),0x0c,0x02,0x00,0x28,0x00,char(0xa5),0x0c,0x02,0x00,0x29,0x00,char(0xa5),0x0c,0x02,0x00,0x2a,0x00,char(0xa5),0x0c,0x02,0x00,0x2b,0x00,char(0xa5),0x0c,0x02,0x00,0x2c,0x00,char(0xa5),0x0c,0x02,0x00,0x2d,0x00,char(0xa5),0x0c,0x02,0x00,0x2e,0x00,char(0xa5),0x0c,0x02,0x00,0x2f,0x00};

#endif // SHOWDESIGNERTEST_H
