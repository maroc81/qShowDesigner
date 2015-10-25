# Show Designer Serial Port Protocol
## Overview
The Show Deisnger serial port portocol was reversed engineered by monitoring data between the SD Monitor windows program and the Show Designer 2 lighting controller.  For more details on decoding the protocol, see the Decode.md file.

The Protocol follows the basic form

Command: ```<Start Byte><Command ID><Command Data>```

Response: ```<Start Byte><Response ID><Response Data Length Low Byte><Response Data Length High Byte><Response Data>```

The start byte is the hex value "a5".  Length appears to range between 0 and 2048.

## Command Summary

Command  | ID | Description
--------- | ---- | -------------
Start Byte | a5 | All commands and responses start with a5.  I don't know how or if a5 is escaped if it appears in the data
Hello? | 01 | Appears to be a "hello" or "ping" command. The command and response consist entirely of "a5 01"
Page No | 02 | Requests the currently selected page number.  The response is the page number minus 1.
Scenes | 03 | Requests all programmed scenes and their names for the given page number.
Fixtures | 04 | Requests all fixtures and their details.
Unknown | 0b | This command and response have been observed but the function is currently unknown.  
Change Page | 0d | Changes page up or down based on argument.
Push Button | 0f | "Pushes" one of the numbered buttons on show designer.

## Connect Sequence

Before the Show Designer will respond to commands, the connect sequence must be performed. After the connect sequence, the controller will respond to commands from any source connected to the serial port until the controller is power cycled.  It may have a time out but one has not yet been observed.

1. Open serial port with settings 38400 8n1 no flow control
2. Change serial port to 1200 8n1 no flow control
3. Set RTS true (assert)
4. Set RTS false (deassert)
5. Send sequence 0x55 0x25 0x05
6. Set port to 38400 8n1 no flow control
7. Wait 1 second
8. Set RTS false twice
9. Send 0xa5 0x01
10. Wait for 0xa5 0x01 response

# Commands

## Hello
### Description
The Hello command is sent by the SD Monitor software as the first command after the connect sequence.  It's possible it could be used during operaiton to make sure the Show Designer is on and responding to commands. However, I have not observed the SD monitor software sending this command any time other than during the connect sequence.

### Command

Byte | Description
----- | ------
a5 | Start byte
01 | Command byte

### Response

Byte | Description
----- | ------
a5 | Start byte
01 | Command byte


## Request Page Number
### Description
Request the currently selected page number on the controller.  Page numbers on the controller start at 1 but start at 0 in the protocol.

### Command

Byte | Description
----- | ------
a5 | Start byte
02 | Request Page Number command ID byte

### Response

Byte | Description
----- | ------
a5 | Start byte
02 | Page Number response ID byte
02 | Response length low byte
00 | Response length high byte
xx | Current page number minus 1 high byte
xx | Current page number minus 1 low byte

## Page Up/Down

### Description
Commands the page number to change by 1 up or down.

### Command

Byte | Description
----- | ------
a5 | Start byte
0d | Change Page command ID byte
00/ff | 00 changes the page down by 1 while ff changes the page up by 1.

### Response

Same as for Request Page Number command

## Request Scenes

### Description
Requests all of the programmed scenes for the specified page number.

### Command

Byte | Description
----- | ------
a5 | Start byte
03 | Request Scenes ID
xx | Scene page number minus 1 high byte
xx | Scene page number minus 1 low byte

### Response

Byte | Description
----- | ------
a5 | Start byte
03 | Request Scenes ID
05 | Response length low byte
03 | Response length high bye
xx | Scene page number minus 1 high byte
xx | Scene page number minus 1 low byte
00 | Number of scenes in response high byte
30 | Number of scenes in response low byte
10 | Unsure but appears to be the length of each scene name
xx | Scene names which are a fixed number of characters for each scene

## Request Fixtures
### Description
Requests all the fixtures, their names, and their channels

### Command
Byte | Description
----- | ------
a5 | Start byte
04 | Request Fixtures ID
ff | xx?

### Response
Byte | Description
----- | ------
a5 | Start byte
04 | Request Fixtures ID
xx | Response length low byte
xx | Response length high byte
xx | Fixture number/id
xx | Fixture type
xx | Number of channels high byte
xx | Number of channels low byte
xx | Unknown 
xx | Unknown
xx | Unknown
xx | Unknown
xx | Unknown
ff | Unknown
ff | Unknown
ff | Unknown
ff | Unknown
xx | Name 16 bytes long padded with spaces to the end 
xx | 16 bytes of null?
xx | 16 bytes of null?
xx | Number of channels?
xx | 8 bytes for each channel name with spaces padding beginning and end to center the name

## Push Button
### Description
Peforms the same action as pushing one of the numbered buttons on the show designer. What happens will be determined by what mode the show designer is in.  If it's in scene mode, the scene programmed to that button will be activated. If it's in fixture mode, that fixture will be selected.

### Command
Byte | Description
----- | ------
a5 | Start byte
0f | Push Button ID
xx | Button number minus 1
00 | Unknown

### Response
No response

## Unknown command with ID 0b
### Description
Unknown command. It may be a way to request the fixture channel values.

### Command
Byte | Description
----- | ------
a5 | Start byte
0b | Command ID
02 | Unknown

### Response
Response format is unknown. A capture of the response is below.

```
a5 09 03 00 90 00 ff
a5 09 03 00 86 00 ff
a5 09 03 00 7c 00 ff
a5 09 03 00 72 00 ff
a5 09 03 00 68 00 ff
a5 09 03 00 99 00 00
a5 09 03 00 98 00 00
a5 09 03 00 63 00 07
a5 09 03 00 65 00 b8
a5 09 03 00 67 00 00
a5 09 03 00 6d 00 07
a5 09 03 00 6e 00 b8
a5 09 03 00 71 00 00
a5 09 03 00 77 00 07
a5 09 03 00 78 00 b8
a5 09 03 00 7b 00 00
a5 09 03 00 81 00 07
a5 09 03 00 82 00 b8
a5 09 03 00 85 00 00
a5 09 03 00 8b 00 07
a5 09 03 00 8c 00 b8
a5 09 03 00 8f 00 00
a5 09 03 00 95 00 07
a5 09 03 00 96 00 b8
```

