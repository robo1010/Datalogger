
Title			: Data logger on AM3358 board 
Platform		: Linux 
Languages and Tools: ARM GCC cross compiler, Minicom, C, Make file, gcc, ctags 
Description		:
 The proposed design implemented system consists of a LM35 Temperate sensor, DS1307 (RTC) can be operated by the AM3358 SoC to retrieve the data from them along with time stamp using I2C protocol and store it in EEPROM where it stores the data even when power is removed and that data can be collected at a later time after that the data will be sent to server, with this system we are able to retrieve the data and save it with the help of EEPROM even there is an interrupt in power.


Role: 
  Study Phase:
High Level Analysis
Understand Basics/terminology of ADC controller & EEPROM and prepare a document.
Project Deliverable: Basics Document
Low Level Analysis
Study ADC controller in AM3358 Technical Reference Manual and undestood the below things.
ADC controller specifications
ADC Functional Block Diagram
ADC Controller Register Programming model
Identify LM35 interface with ADC channel with the help of schematic diagram.
Understood EEPROM Write I2C communication protocol format.
Prepare ADC-AM3358 Functional Block diagram
Prepare EEPROM-AM3358 Functional Block diagram
Project Deliverable: Document
Implementation:
Bootloader stage
Enable ADC & I2C1 controller mux configuration and clock in u-boot source code.
Kernel stage
DTS Modification:
Add ADC device controller mux configuration if needed, base address, interrupt number and low-level device driver compatibility name in device tree source code. 
Add EEPROM I2C1 slave information in device tree source code.
Project Deliverable: patch
Driver Modifications:
Identify ADC and EEPROM I2C slave low level driver and find out low level driver comes which Linux subsystem. 
Project Deliverable: patch
             Application
Wrote an application to read temperature value in digital format and convert in to degree centigrade format. And wrote an EEPROM test application to store temperature value in to EEPROM.
