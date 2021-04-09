import os
import  xlrd
import datetime as d
import sys
import re
reload(sys)
sys.setdefaultencoding('utf-8')
path='StringList.xlsx'
data=xlrd.open_workbook(path)
sheets=data.sheets()
Translation_based_on_FFL=data.sheet_by_name(u'Translation')
n_of_rows=Translation_based_on_FFL.nrows
Specialtxt=open('Special.txt','w+')

#-----------------Special treatment--------------
merged_List = []
for i in range(len(Translation_based_on_FFL.merged_cells)):
    if Translation_based_on_FFL.merged_cells[i][2] == 1 and Translation_based_on_FFL.merged_cells[i][3] == 2:
        merged_List.append(Translation_based_on_FFL.merged_cells[i][:2])
#---------------------------------------------------Localization Table.pot---------------------------------------------------


memory = []
for i in range(2,n_of_rows):
    SpecialOrNo = 0
    Specialrow = 0
    Specialnum = 0
    for j in range(len(merged_List)):
        if i >= merged_List[j][0] and i < merged_List[j][1]:
            SpecialOrNo = 1
            Specialrow = merged_List[j][0]
            Specialnum = i - merged_List[j][0] + 1
    if SpecialOrNo == 0:
        Specialrow = i
    text1 = str(Translation_based_on_FFL.cell(Specialrow,1).value)
    if text1 != "":
        if "Alert-" in text1:
            text1 = re.sub("[^0-9]", "_", text1)
            text1 = text1.strip("_")
            text1 = "AlertString_"+text1
            if SpecialOrNo ==1:
                text1 = text1+"_"+str(Specialnum)
                Specialtxt.write("String:"+text1+".need to deal by Special\n")
                print("String:"+text1+".need to deal by Special")
        else:
            text1 = re.sub("[^a-zA-Z0-9]", "_", text1)
            text1 = text1.strip("_")
            if SpecialOrNo ==1:
                text1 = text1+"_"+str(Specialnum)
        if text1 in memory:
            print(text1+" is duplicate")
        else:
            memory.append(text1)

print('Localization Table check succeed!\n')