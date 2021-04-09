try:
  import xml.etree.cElementTree as ET
  print("cElementTree")
except ImportError:
  import xml.etree.ElementTree as ET
  print("ElementTree")

#import pandas as pd

########################################################################################
xmlfilename = "Menu.xml"
START_PORT = '/***auto generator api code start***/'
END_PORT = '/***auto generator api code end***/'

listxmlfilename = "MenuList.xml"
LISTSTART_PORT = '/***auto generator list api code start***/'
LISTEND_PORT = '/***auto generator list api code end***/'
########################################################################################
#tree = ET.parse("test.xml")


def cntNode(node):
    cnt = len(list(node))
    #if cnt:
        #print(cnt)
    return cnt
def functionNote(funname):
    note=[]
    note.append("		//===========================auto generate,do not modify========================\n");
    note.append("		/// @Function Name     :  "+funname+"\n");
    note.append("		/// @Description       :  set value.\n");
    note.append("		/// @Parameters        :  const char*\n");
    note.append("		/// @Return            :  None\n");
    note.append("		/// @Critical Section  :  None\n");
    note.append("		//==============================================================================\n");
    return note

def ergodicNode(node,tag):
    returTxt=[]
    curtag = tag+node.tag
    #print ("curtag:",curtag)
    #print("len:",len(node.attrib))
    #print("len:",len(node.text.strip()))
    if len(node.attrib):
        #returTxt.append("\n")
        funname = "		void "+curtag+"SetValue"+"( const char* text);"
        returTxt +=functionNote(curtag+"SetValue")
        returTxt.append(funname)
        returTxt.append("\n")
        #print(returTxt)
        #print ("  attr type:",node.attrib["type"])
    #if len(node.text.strip()):
        #print ("       text:",node.text)
    if cntNode(node):
        returTxt.append("\n")
        for child in node:
            returTxt += ergodicNode(child,curtag)
    return returTxt

def funDefinition(curtag,taglist,attr):
    tab = "	"
    returTxt =[]
    returTxt.append("\nvoid dataSourceApi::"+curtag+"SetValue"+"( const char* text)\n")
    returTxt.append("{")
    returTxt.append("	Xmldatasource* XmldatasourcePtr;\n")
    returTxt.append("	kanzi::map<kanzi::string, Xmldatasource*>::iterator it = mMapXmldatasource.find(\""+xmlfilename+"\");\n")
    returTxt.append("	if (it != mMapXmldatasource.end())\n")
    returTxt.append("	{\n")
    returTxt.append("		XmldatasourcePtr =  it->second;\n")
    returTxt.append("	}\n")
    returTxt.append(tab+"kanzi::DataObjectSharedPtr root = XmldatasourcePtr->getData();\n")
    returTxt.append(tab+"if (root)\n")
    returTxt.append(tab+"{\n")
    for i in range(len(taglist)):
        tab +="	"
        if i>0:
            returTxt.append(tab+"kanzi::DataObjectSharedPtr "+taglist[i]+" = "+taglist[i-1]+".get()->findChild(\""+taglist[i].split(taglist[i-1],1)[1]+"\");\n")
        else:
            returTxt.append(tab+"kanzi::DataObjectSharedPtr "+taglist[i]+" = root.get()->findChild(\""+taglist[i]+"\");\n")
        print(taglist[i])
        returTxt.append(tab+"if ("+taglist[i]+")\n")
        returTxt.append(tab+"{\n")
    tab +="	"
    returTxt.append(tab+"updateObject("+curtag+", \""+attr+"\", text);\n")
    #returTxt.append(tab+"XmldatasourcePtr->notifyModified();\n")
    returTxt.append("				}\n")
    returTxt.append("			}\n")
    returTxt.append("		}\n")
    returTxt.append("	}\n")
    returTxt.append("}\n")
    #for ls in returTxt:
        #print(ls)
    return returTxt

def ergodicNodeCpp(node,tag,h,taglist):
    #taglist = []
    returTxt=[]
    print(h)
    curtag = tag+node.tag
    if(len(taglist)<=h):
        taglist.append(curtag)
    else:
        taglist[h] = curtag
    h +=1
    print(curtag)
    
    print(taglist)
    #print(textGetChildNode)
    #print ("curtag:",curtag)
    #print("len:",len(node.attrib))
    #print("len:",len(node.text.strip()))
    if len(node.attrib):
        returTxt +=functionNote(curtag+"SetValue")
        returTxt +=funDefinition(curtag,taglist,node.attrib['type'])
    if cntNode(node):
        returTxt.append("\n")
        for child in node:
            returTxt += ergodicNodeCpp(child,curtag,h,taglist)
    return returTxt
        
#dataSourceApi.h
#dataSourceApi.cpp
def gendataSourceApi_h():
    tree = ET.ElementTree(file=xmlfilename)
    root = tree.getroot()
    list(root)
    dfText = ergodicNode(root,"")
    for ls in dfText:
        print(ls)
    return dfText

def gendataSourceApi_cpp():
    tree = ET.ElementTree(file=xmlfilename)
    root = tree.getroot()
    list(root)
    taglist = []
    dfText = ergodicNodeCpp(root,"",0,taglist)
    return dfText

def ListfunctionNote(funname,structname):
    note=[]
    note.append("		//===========================auto generate,do not modify========================\n");
    note.append("		/// @Function Name     :  "+funname+"\n");
    note.append("		/// @Description       :  set value.\n");
    note.append("		/// @Parameters        :  kanzi::vector<"+structname+"> vec\n");
    note.append("		/// @Return            :  None\n");
    note.append("		/// @Critical Section  :  None\n");
    note.append("		//==============================================================================\n");
    return note

def ListergodicNode(node,tag):
    returTxt=[]
    curtag = tag+node.tag
    print ("curtag:",curtag)
    
    #print("len:",len(node.text.strip()))
    if len(node.attrib)and node.attrib['type']=='list':
      #print("type :",node.attrib['type'])
      listname = node.tag
      funname = curtag+"Update"
      structname =""
      struct ={}
      for child in node:
        if("items"==child.tag):
          item = child[0]
          structname = "s"+node.tag.capitalize()
          for prop in item:
            struct[prop.tag]= prop.attrib['type']
          print(struct)
      returTxt +=ListfunctionNote(funname,structname)
      returTxt.append("		struct "+structname+"\n")      
      returTxt.append("		{\n")
      for key in struct:
        returTxt.append("			kanzi::string "+key+";//"+struct[key]+"\n")
      returTxt.append("		};\n")
      returTxt.append("		void "+funname+"(kanzi::vector<"+structname+"> vec);\n")
    else:
      if cntNode(node):
          returTxt.append("\n")
          for child in node:
            returTxt += ListergodicNode(child,curtag)
    return returTxt

def ListfunDefinition(funname,structname,taglist,itemname,struct):
    tab = "	"
    returTxt =[]
    returTxt.append("\nvoid dataSourceApi::"+funname+"(kanzi::vector<"+structname+"> vec)\n")
    returTxt.append("{")
    returTxt.append("	Xmldatasource* XmldatasourcePtr;\n")
    returTxt.append("	kanzi::map<kanzi::string, Xmldatasource*>::iterator it = mMapXmldatasource.find(\""+listxmlfilename+"\");\n")
    returTxt.append("	if (it != mMapXmldatasource.end())\n")
    returTxt.append("	{\n")
    returTxt.append("		XmldatasourcePtr =  it->second;\n")
    returTxt.append("	}\n")
    returTxt.append(tab+"kanzi::DataObjectSharedPtr root = XmldatasourcePtr->getData();\n")
    returTxt.append(tab+"if (root)\n")
    returTxt.append(tab+"{\n")
    for i in range(len(taglist)):
        tab +="	"
        if i>0:
            returTxt.append(tab+"kanzi::DataObjectSharedPtr "+taglist[i]+" = "+taglist[i-1]+".get()->findChild(\""+taglist[i].split(taglist[i-1],1)[1]+"\");\n")
        else:
            returTxt.append(tab+"kanzi::DataObjectSharedPtr "+taglist[i]+" = root.get()->findChild(\""+taglist[i]+"\");\n")
        print(taglist[i])
        returTxt.append(tab+"if ("+taglist[i]+")\n")
        returTxt.append(tab+"{\n")
        if i>0:
          returTxt.append(tab+"	DataObjectStaticListSharedPtr list = dynamic_pointer_cast<DataObjectStaticList>("+taglist[i]+");\n")
    tab +="	"
    returTxt.append(tab+"list.get()->clearList();\n")
    returTxt.append(tab+"for (int i = 0; i<vec.size(); i++)\n")
    returTxt.append(tab+"{\n")
    returTxt.append(tab+"	DataObjectSharedPtr rootObject = make_shared<DataObject>(XmldatasourcePtr->getDomain(), \"Item root\");\n")
    returTxt.append(tab+"	kanzi::DataObjectSharedPtr itemobject = nullptr;\n")
    returTxt.append(tab+"	itemobject = addObject(XmldatasourcePtr->getDomain(), \"\",\""+itemname+"\",\"\");\n")
    returTxt.append(tab+"	rootObject->addChild(itemobject);\n")
    returTxt.append(tab+"	kanzi::DataObjectSharedPtr object = nullptr;\n")
    for key in struct:
      returTxt.append(tab+"	object = addObject(XmldatasourcePtr->getDomain(), \""+struct[key]+"\", \""+key+"\", vec[i]."+key+".c_str());\n")
      returTxt.append(tab+"	itemobject->addChild(object);\n")
    returTxt.append(tab+"	list->addItem(rootObject);\n")
    returTxt.append(tab+"	printf(\"%s list cnt %d\\n\", list->getName().c_str(), list->itemCount());\n")
    returTxt.append("				}\n")
    #returTxt.append("				XmldatasourcePtr->notifyModified();\n")
    
    returTxt.append("			}\n")
    returTxt.append("		}\n")
    returTxt.append("	}\n")
    returTxt.append("}\n")
    for ls in returTxt:
        print(ls)
    return returTxt

def ListergodicNodeCpp(node,tag,h,taglist):
    #taglist = []
    returTxt=[]
    print(h)
    curtag = tag+node.tag
    if(len(taglist)<=h):
        taglist.append(curtag)
    else:
        taglist[h] = curtag
    h +=1
    print(curtag)
    
    print(taglist)
    #print(textGetChildNode)
    #print ("curtag:",curtag)
    #print("len:",len(node.attrib))
    #print("len:",len(node.text.strip()))
    if len(node.attrib)and node.attrib['type']=='list':
      #print("type :",node.attrib['type'])
      listname = node.tag
      funname = curtag+"Update"
      structname =""
      itemname = ""
      struct ={}
      for child in node:
        if("items"==child.tag):
          item = child[0]
          itemname = item.tag
          structname = "s"+node.tag.capitalize()
          for prop in item:
            struct[prop.tag]= prop.attrib['type']
          print(struct)
      returTxt +=ListfunctionNote(funname,structname)
      returTxt +=ListfunDefinition(funname,structname,taglist,itemname,struct)
    else:
      if cntNode(node):
          returTxt.append("\n")
          for child in node:
            returTxt += ListergodicNodeCpp(child,curtag,h,taglist)
    
    return returTxt
 

def gendataSourceApiList_h():
    tree = ET.ElementTree(file=listxmlfilename)
    root = tree.getroot()
    list(root)
    dfText = ListergodicNode(root,"")
    for ls in dfText:
        print(ls)
    return dfText

def gendataSourceApiList_cpp():
    tree = ET.ElementTree(file=listxmlfilename)
    root = tree.getroot()
    list(root)
    taglist = []
    dfText = ListergodicNodeCpp(root,"",0,taglist)
    return dfText

 
    

def output_to_cpp_file(target_file, df,startPort,endPort, out_file=None):
    print('Start to write the cpp/h file...')
    try:
        with open(target_file, 'r',encoding='utf-8') as f:
            content = f.readlines()
    except:
        print('Please check the target file!')
        return None
    
    ix_start, ix_end = 0, 0
    for lineno, line in enumerate(content):
        if not ix_start and line.strip() == startPort:
            ix_start = lineno
        if ix_start and line.strip() == endPort:
            ix_end = lineno
            break
    #print(df)
    output = content[:ix_start+1] + df + content[ix_end:]
    #print(output)
 
      
    if not out_file:
        out_file = './dataSourceApi.' + target_file.split('.')[-1]
    with open(out_file, 'w', encoding='utf-8') as f:
        for line in output:
            f.write(line)
    
        
    print('Done!\nThe output file is: {}'.format(out_file))
    
    return None

def main():
    df= gendataSourceApi_h()
    if df is not None:
        output_to_cpp_file("./dataSourceApi.h", df,START_PORT,END_PORT,"dataSourceApi.h")
    else:
        print('Quit!')
    
    df= gendataSourceApi_cpp()
    
    if df is not None:
        output_to_cpp_file("./dataSourceApi.cpp", df,START_PORT,END_PORT,"dataSourceApi.cpp")
    else:
        print('Quit!')

    df=gendataSourceApiList_h()
    print(df)

    if df is not None:
        output_to_cpp_file("./dataSourceApi.h", df,LISTSTART_PORT,LISTEND_PORT,"dataSourceApi.h")
    else:
        print('Quit!')
      
    df= gendataSourceApiList_cpp()
    
    if df is not None:
        output_to_cpp_file("./dataSourceApi.cpp", df,LISTSTART_PORT,LISTEND_PORT,"dataSourceApi.cpp")
    else:
        print('Quit!')  
    

if __name__ == '__main__':
    main()
    
