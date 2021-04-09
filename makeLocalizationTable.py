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

def createLocalizationTable(path, col, languageType, isPotFile = 0):
    filePo=open(path,'w+')
    filePo.truncate()
    filePo.write('msgid ""'+'\n')
    filePo.write('msgstr ""'+'\n')
    filePo.write('"Project-Id-Version: Kanzi Studio\\n"'+'\n')
    filePo.write('"POT-Creation-Date: '+d.datetime.now().strftime("%m/%d/%Y %H:%M:%S")+'"\\n"'+'\n')
    filePo.write('"POT-Revision-Date: '+d.datetime.now().strftime("%m/%d/%Y %H:%M:%S")+'"\\n"'+'\n')
    filePo.write('"Last-Translator: \\n"'+'\n')
    filePo.write('"Language-Team: \\n"'+'\n')
    filePo.write('"MIME-Version: 1.0\\n"'+'\n')
    filePo.write('"Content-Type: text/plain; charset=UTF-8\\n"'+'\n')
    filePo.write('"Content-Transfer-Encoding: 8bit\\n"'+'\n')
    filePo.write('"X-Generator: Kanzi Studio\\n"'+'\n')
    filePo.write('"X-Poedit-Basepath: ."'+'\n')
    filePo.write('"Plural-Forms: nplurals=2; plural=(n != 1);\\n"'+'\n')
    if 0 == isPotFile:
        filePo.write('"Language: '+languageType+'\\n"'+'\n')
    filePo.write('"X-Poedit-KeywordsList: \\n"'+'\n')
    filePo.write('\n')

    filePo.write('msgctxt "special"\n')
    filePo.write('msgid "special"\n')
    if 0 == isPotFile:
        filePo.write('msgstr "special"\n\n')
    else:
        filePo.write('msgstr ""\n\n')

    filePo.write('msgctxt "lackString"\n')
    filePo.write('msgid "lackString"\n')
    if 0 == isPotFile:
        filePo.write('msgstr "lackString"\n\n')
    else:
        filePo.write('msgstr ""\n\n')

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
            else:
                text1 = re.sub("[^a-zA-Z0-9]", "_", text1)
                text1 = text1.strip("_")
                if SpecialOrNo ==1:
                    text1 = text1+"_"+str(Specialnum)

            text2=str(Translation_based_on_FFL.cell(i,2).value)
            text2=text2.replace('\n','')
            text2=text2.replace('\r','')
            text2=text2.split('\\n')
            for k in range(len(text2)):
                text2[k] = text2[k].strip(' ')
    
            if len(text2) > 1:
                filePo.write('msgid ""'+'\n')
                for j in range(0,len(text2)-1):
                    filePo.write('"'+text2[j]+'\\n'+'"\n')
                filePo.write('"'+text2[len(text2)-1]+'"\n')
            elif text2[0] == '42':
                filePo.write('msgid "%N/A"\n')
            else:
                filePo.write('msgid "'+text2[0]+'"\n')

            if 0 == isPotFile:
                text3=str(Translation_based_on_FFL.cell(i,col).value)
                text3=text3.replace('\n','')
                text3=text3.replace('\r','')            
                text3=text3.split('\\n')
                for k in range(len(text3)):
                    text3[k] = text3[k].strip(' ')
                filePo.write('msgctxt "'+text1+'"\n')

                if len(text3) > 1:
                    filePo.write('msgstr ""'+'\n')
                    for k in range(0,len(text3)-1):
                        filePo.write('"'+text3[k]+'\\n'+'"\n')
                    filePo.write('"'+text3[len(text3)-1]+'"\n')
                elif text3[0] == '42':
                    filePo.write('msgstr "%N/A"\n')
                else:
                    filePo.write('msgstr "'+text3[0]+'"\n')
            else:
                filePo.write('msgstr ""\n')

            filePo.write('\n')

    filePo.close()
    print(languageType + ' create succeed!\n')






createLocalizationTable('Localization Table.pot', 1, 'Localization Table', 1)
createLocalizationTable('Localization Table_zh-CHS.po', 2, 'zh-CHS')
createLocalizationTable('Localization Table_en-US.po', 5, 'en-US')
createLocalizationTable('Localization Table_es-ES.po', 8, 'es-ES')
createLocalizationTable('Localization Table_ar-AR.po', 11, 'ar-AR')
createLocalizationTable('Localization Table_ru-RU.po', 14, 'ru-RU')
createLocalizationTable('Localization Table_uk-UK.po', 17, 'uk-UK')
