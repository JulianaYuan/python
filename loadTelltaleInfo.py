import os
import xlrd
import sys
import imp
imp.reload(sys)
#reload(sys)
#sys.setdefaultencoding('utf-8')
path = 'Telltale.xlsx'
data = xlrd.open_workbook(path)
sheets=data.sheets()
TT_infomation_list = data.sheet_by_name(u'TT_infomation_list')
n_of_rows = TT_infomation_list.nrows
cppInsertBuf = []
hppInsertBuf = []

freadCpp = open("..\..\HMIAdapter\source\HMITelltaleInd.cpp", 'r')
fwriteCpp = open("HMITelltaleInd.cpp", 'w+')
fwriteCpp.truncate()
#cppBufferTmp = []
lines = freadCpp.readlines()
cppRow = 0
writeLine = 0
for lines in lines:
  cppRow = cppRow + 1
  if "m_TTForPPS[" not in lines:
    cppInsertBuf.append(lines)
  if "void HMITelltaleInd::initTTDataForPPS()" in lines:
    writeLine = cppRow

freadHpp = open("..\..\HMIAdapter\include\HMIAdapterDefine.h", 'r')
fwriteHpp = open("HMIAdapterDefine.h", 'w+')
fwriteHpp.truncate()
lines = freadHpp.readlines()
hppRow = 0
writeRowHpp = 0
for lines in lines:
  hppRow = hppRow + 1
  if "TTID_" not in lines:
    hppInsertBuf.append(lines)
  if "enum TTID" in lines:
    writeRowHpp = hppRow

#--------------------------- load telltale list and write for HmiAdapter ---------------------------
  fuid = str(TT_infomation_list.cell(i,3).value)
  dataid = str(TT_infomation_list.cell(i,4).value)
  enumData = str(TT_infomation_list.cell(i,2).value)
  chimeOnId = str(TT_infomation_list.cell(i,27).value)
  chimeOffId = str(TT_infomation_list.cell(i,28).value)
  chimeFlashId = str(TT_infomation_list.cell(i,29).value)
  fsTTAction = str(TT_infomation_list.cell(i,31).value)
  if len(chimeOnId) <= 0:
    chimeOnId = "0"
  else:
    chimeOnId = str(int(TT_infomation_list.cell(i,27).value))
  if len(chimeOffId) <= 0:
    chimeOffId = "0"
  else:
    chimeOffId = str(int(TT_infomation_list.cell(i,28).value))
  if len(chimeFlashId) <= 0:
    chimeFlashId = "0"
  else:
    chimeFlashId = str(int(TT_infomation_list.cell(i,29).value))
  if len(fsTTAction) <= 0:
    fsTTAction = "0"
  else:
    fsTTAction = str(int(TT_infomation_list.cell(i,31).value))
  if len(enumData) > 0:
    hppInsertBuf.insert(writeRowHpp, "  " + enumData + ",\n")
    if (len(fuid) and len(dataid) > 0):
      fuid = str(int(TT_infomation_list.cell(i,3).value))
      dataid = str(int(TT_infomation_list.cell(i,4).value))
      cppInsertBuf.insert(writeLine, " m_ttInfo.insert(std::pair<FuIdDataId, TelltaleInfo>(FuIdDataId(" + fuid + ", " + dataid + "), TelltaleInfo(" + enumData + ", " + chimeOnId + ", " + chimeOffId + ", " + chimeFlashId + ", " + fsTTAction + ", ChimeStatus_Off, TTstatus_Off, false)));\n")
    else:
      cppInsertBuf.insert(writeLine, "  // m_TTForPPS[][] = " + enumData + ";\n")
  writeLine = writeLine + 1
  writeRowHpp = writeRowHpp + 1
  print ("\n")
#cppBufferTmp.insert(writeLine, cppInsertBuf)
hppInsertBuf.insert(writeRowHpp, "  TTID_COUNT\n")
s=''.join(cppInsertBuf)
ss =''.join(hppInsertBuf)
fwriteCpp.write(s)
fwriteHpp.write(ss)
fwriteCpp.close()
fwriteHpp.close()
