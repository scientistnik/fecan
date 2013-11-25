  
  USB<>CAN Control v1.0b8
  
  Windows application for AVR based USB<>CAN adaptor
  by Michael Wolf



  Revision History

  when         what    who			          why
  07/09/05     v1.0b1  Michael Wolf       First release
  18/09/05     v1.0b2  Michael Wolf       *Complete review with many
                                           improvments and new features
  16/10/05     v1.0b3  Michael Wolf       *minor change to work with empty
                                           device serial field (required if
                                           FT245 EEPROM is empty)
  22/10/05     v1.0b4  Michael Wolf       -fixed bug in time stamp detection
                                          +added support for remote frame
                                           transmit and receive
                                           (requires at least interface
                                            firmware v1.3)
  23/11/05     v1.0b5  Michael Wolf       *changed dialog window
                                          +added cyclic message send option
                                          -removed burst send option
                                          +added ASCII data display option
  10/03/06     v1.0b6  Michael Wolf       *added connection timeouts
  02/08/09     v1.0b8  Michael Wolf       - bug fix for cyclic messages
					  + added more fixed Baudrates
.:...........................................................................:.

  This is a simple Windows application to control my USB<>CAN bus
  interface. There is support for all implemented protocol commands
  descripted in interface hardware documentation.
  
  The application communicates via USB with the interface hardware
  using FTDI's D2XX USB driver which can be downloaded here:
  
  http://www.ftdichip.com/Drivers/FT232-FT245Drivers.htm#D2XX
  
  Please follow the installation guides and documents from FTDI for
  driver installation. Especially when changing from VCP driver to
  D2XX driver.
  
  
  The application is in beta state. Please contact me, Michael, for
  bug reports, reuests or support via
  
  Email: michael (AT) mictronics.de
  WWW: http://www.mictronics.de
  