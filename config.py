import os
import datetime


def fun():
  
  f=input("plz enter the folder name plz:")
  d=datetime.datetime.now()
  day=str(d.day)
  month=d.strftime("%B")
  year=str(d.year)
  os.mkdir(f)
  os.chdir(f)
  filetype='This Header file '
  signature ='/**********************************************************************************************\n\
Author :Mohamed Ibrahem, Mahmoud Gamal\nVersion:1.0\nDate:'+day+' '+month+' '+year+\
  '\nDescription:'+filetype+'is used to interface with the '+f+ ' module in STM32f10x evaluation kit'+'\n\
***********************************************************************************************/\n'
  f2=open(f+'_interface.h','w')
  s='_interface_h'
  s=s.upper()
  f2.write(signature)
  f2.write('#ifndef '+f+s+'\n')
  f2.write('#define '+f+s+'\n\n\n\n')
  f2.write("#endif")
  #filetype='This is header file'
  f3=open(f+'_cnfg.h','w')
  s='_cnfg_h'
  s=s.upper()
  f3.write(signature)
  f3.write('#ifndef '+f+s+'\n')
  f3.write('#define '+f+s+'\n\n\n\n')
  f3.write("#endif")
  filetype='This Source file '
  signature ='/**********************************************************************************************\n\
Author :Mohamed Ibrahem, Mahmoud Gamal\nVersion:1.0\nDate:'+day+' '+month+' '+year+\
  '\nDescription:'+filetype+'is used to interface with the '+f+ ' module in STM32f10x evaluation kit'+'\n\
***********************************************************************************************/\n'
  f4=open(f+'_program.c','w')
  f4.write(signature)
  f4.write('#include \"STD_TYPES.h\"\n')
  f4.write('#include '"\""+f+'_interface.h'+"\""+'\n')
  f4.write('#include '"\""+f+'_cnfg.h'+"\""+'\n')
  #filetype='This is source of the configuration file'
  
  f5=open(f+'_cnfg.c','w')
  s='_cnfg_h'
  s=s.upper()
  f5.write(signature)
  f5.write('#include \"STD_TYPES.h\"\n')
  f5.write('#include '"\""+f+'_interface.h'+"\""+'\n')
  f5.write('#include '"\""+f+'_cnfg.h'+"\""+'\n')
  
fun()