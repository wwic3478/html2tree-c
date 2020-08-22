# html2txt-c
将html文本段复制之后使用命令行将其转为txt文件


#使用条件

本文件只针对是ANSI编码文件

本软件暂时不能直接运行，需要依靠cmd或powershell才能运行（20200822）


#详细使用方法

1.在网页上按下“F12”进入开发者模式，然后选择要复制的文字，将html文件复制进剪切板

2.使用notepad之类的文本文件编辑器打开，并将其转换为ANSI文件进行保存

3.打开cmd并切换至此目录（此处一定要注意，win10不能使用powershell！！！）

4.输入命令“html2txt-c.exe”，敲入前面几个字符后可按下tab自动补全

5.输入要转换的文件，如“1.txt”

6.指定输出位置，推荐“ > 2.txt”


#使用示例

html2txt-c.exe 1.txt > 2.txt

html2txt-c.exe src.txt > dst.txt

