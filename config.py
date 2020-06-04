import os
import shutil

def main():
  folder=input("Please enter the driver name: ")
  os.mkdir(folder)
  os.chdir(folder)
  config = folder+'_config.h'
  register = folder+'_cnfg.c'
  interface = folder+'_interface.h'
  program = folder+'_program.c'
  
  configFile=open(config,'w+')  
  registerFile=open(register,'w+')
  interfaceFile=open(interface,'w+')
  programFile=open(program,'w+')
  
  c='/**************************************************** \n \t Author: Mahmoud Gamal\n \t Version: 1.0\n************************************************/\n#ifndef '+config[:-2].upper()+ '_H\n#define '+config[:-2].upper()+'_H\n\n#endif'
  configFile.write(c)                                                                 
  r='/**************************************************** \n \t Author: Mahmoud Gamal\n \t Version: 1.0\n************************************************/\n#include "std_types.h"\n#include "bit_math.h"\n'+'#include "'+config+'"\n'+'#include "'+interface+'"\n'
  registerFile.write(r)
  i='/**************************************************** \n \t Author: Mahmoud Gamal\n \t Version: 1.0\n************************************************/\n#ifndef '+interface[:-2].upper()+ '_H\n#define '+interface[:-2].upper()+'_H\n\n#endif'
  interfaceFile.write(i)
  p='/**************************************************** \n \t Author: Mahmoud Gamal\n \t Version: 1.0\n************************************************/\n#include "std_types.h"\n#include "bit_math.h"\n'+'#include "'+config+'"\n'+'#include "'+interface+'"\n'
  programFile.write(p)
  
  
main()