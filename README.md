# QTNotepad
Разработка текстового редактора с использованием Qt.  
  
Поддерживает работу с несколькими файлами одновременно с использованием QTabWidget  
Автоматически определяет расширение открываемого файла  
Если файл имеет расширение файлов исходного кода программы (например, .h, .cpp или .hpp — расширения файлов исходного кода программ на C++),  
тогда при открытии выполняет подсветку синтаксиса с помощью класса QSyntaxHighlighter.  

File:  
New (Создание нового документа)  
Open (Открытие существующего документа на основе QFileDialog)  
Save (Сохранение документа из активной вкладки)  
Save as... (сохранение в указанном формате на основе QFileDialog)  
Save All (Сохранить все открытые документы)  
Close (закрыть текущий документ)  
Close All (закрытие всех открытых документов)  
Exit (Закрыть редактор с диалогом сохранения несохраненных документов)  


-----------------------------------------------

Development of a text editor using Qt.     

Supports the ability to open multiple files by using the tab widget (QTabWidget)
Analyzes file extensions when opened.
If the file has the extension of the program source code files (for example, .h, .cpp or .hpp – extensions of the source code files of C++ programs),
then when opened, performs syntax coloring using the QSyntaxHighlighter class.

File:
New (Creating a new document)
Open (Opening an existing document based on QFileDialog)
Save (Saving the document from the active tab)
Save as... (Saving in a specified format based on QFileDialog)
Save All (Save all open documents)
Close (Close the current document)
Close All (Closing all open documents)
Exit (Close the editor with the dialog for saving unsaved documents)

Edit:
Cut
Copy
Paste
Remove
Select All


View:
Show Explorer 
Show Open Document Browser
