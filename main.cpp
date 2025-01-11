#include <vector>
#include <iostream>
#include <string>
#include <filesystem>

#include "ReadWrite_FromDisk_Cpp17__class.h"




int main
(
    //Список методов читать в файле "Readme".

     ReadWrite_FromDisk_Cpp17__class ReadWrite_FromDisk;        //Создадим обьект.


	 //------------------------------------------------------
     //Указание пути ВСЕГДА должно завершатся символом - "\\"

	 //ЗАРАНЕЕ СОЗДАИМ ВСЕ ВОЗМОЖНЫЕ ФОРМАТЫ ПУТЕЙ к ФАЙЛУ, которые принимают ВСЕ шаблонные функции:


	 std::string path_string_ASCII               = "D:\\Мусор\\";                              //Этот путь используется, как в качесве ASCII
	 std::string File_Name_string_ASCII          = "Test1.txt";                       //Этот путь используется, как в качесве ASCII

	 std::wstring path_wstring_UTF16             = L"D:\\Мусор\\";                           //Этот путь используется, как в качесве UTF16 для std::wstring - кодировка для wstring зависит от платформы.
	 std::wstring File_Name_wstring_UTF16        = L"东Test1.txt";                      //Этот путь используется, как в качесве UTF16 для std::wstring - кодировка для wstring зависит от платформы.

	 std::string path_string_UTF8                = u8"D:\\Мусор\\";                            //Этот путь используется, как в качесве UTF8
	 std::string File_Name_string_UTF8           = u8"东Test1.txt";                       //Этот путь используется, как в качесве UTF8

	 std::u16string path_u16string_UTF16         = u"D:\\Мусор\\";                      //Этот путь используется, как в качесве UTF16
	 std::u16string File_Name_u16string_UTF16    = u"东Test1.txt";                 //Этот путь используется, как в качесве UTF16

	 std::u32string path_u32string_UTF32         = U"D:\\Мусор\\";                      //Этот путь используется, как в качесве UTF32
	 std::u32string File_Name_u32string_UTF32    = U"东Test1.txt";                 //Этот путь используется, как в качесве UTF32


	 std::string    Full_path_file_name_string_ASCII       = "D:\\Мусор\\Test1.txt";             //Это путь принимающий сразу полный путь: то есть и путь содержащий полный путь до файла включая файл.
	 std::wstring   Full_path_file_name_wstring_UTF16      = L"D:\\Мусор\\东Test1.txt";          //Это путь принимающий сразу полный путь: то есть и путь содержащий полный путь до файла включая файл.
	 std::string    Full_path_file_name_string_UTF8        = u8"D:\\Мусор\\东Test1.txt";            //Это путь принимающий сразу полный путь: то есть и путь содержащий полный путь до файла включая файл.
	 std::u16string Full_path_file_name_u16string_UTF16    = u"D:\\Мусор\\东Test1.txt";      //Это путь принимающий сразу полный путь: то есть и путь содержащий полный путь до файла включая файл.
	 std::u32string Full_path_file_name_u32string_UTF32    = U"D:\\Мусор\\东Test1.txt";      //Это путь принимающий сразу полный путь: то есть и путь содержащий полный путь до файла включая файл.
	 //------------------------------------------------------




	 
	 //-------------------------------------------------------------------------1:read__FullFile_to_StringBack:Начало--------------------------------------------------------------------------------------------
	 
	 //Это шаблонная функция - считывают все содержимое файла и добавляет в конец предооставленного ей "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 std::string string_for_read_1 = "Hello1";                       //std::string - куда функция добавить считанные из файла данные.
 
	 string_for_read_1.resize(0);   //Так как функция доавбляет в конец существующего "string_for_read", то если там уже есть какие то данные, а записать нужно к примеру с начала "string_for_read" - то зануляем его прежде, чем вызвать функцию.


	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_1  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::string>(path_string_ASCII,       File_Name_string_ASCII, string_for_read_1);        //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_1  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::string>(path_string_UTF8, File_Name_string_UTF8, string_for_read_1);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_1   = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::wstring>(path_wstring_UTF16,     File_Name_wstring_UTF16, string_for_read_1);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_1  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, string_for_read_1);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_1  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, string_for_read_1);     //Вызываем. 
	 
	 //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_1 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_1: OK" << std::endl;
		 std::cout << "string_for_read_1:" << string_for_read_1 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_1:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


     //-------------------------------------------------------------------------1:read__FullFile_to_StringBack:Конец--------------------------------------------------------------------------------------------



	 //-------------------------------------------------------------------------2:read__FullFile_to_StringBack:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают все содержимое файла и добавляет в конец предооставленного ей "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 std::string string_for_read_3 = "Hello1";                  //std::string - куда функция добавить считанные из файла данные.

	 string_for_read_3.resize(0);   //Так как функция доавбляет в конец существующего "string_for_read", то если там уже есть какие то данные, а записать нужно к примеру с начала "string_for_read" - то зануляем его прежде, чем вызвать функцию.


	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_3  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::string>(Full_path_file_name_string_ASCII, string_for_read_3);         //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_3  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::string>(Full_path_file_name_string_UTF8, string_for_read_3);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_3    = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::wstring>(Full_path_file_name_wstring_UTF16, string_for_read_3);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_3  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::u16string>(Full_path_file_name_u16string_UTF16, string_for_read_3);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_3  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::u32string>(Full_path_file_name_u32string_UTF32, string_for_read_3);     //Вызываем.

	  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_3 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_3: OK" << std::endl;
		 std::cout << "string_for_read_3:" << string_for_read_3 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_3:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------2:read__FullFile_to_StringBack:Конец--------------------------------------------------------------------------------------------





	 //------------------------------------------------------------------------------3:read__PartFile_to_StringBack:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в конец предооставленного ей "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 std::string string_for_read_5 = "Hello1";              //std::string - куда функция добавить считанные данные.

	 const size_t pos_beg_5 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.               Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_5 = 4;                              //Позиция байта в файле, ДО которого включительно необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт. Выход за пределы файла не контролируется, в случае выхода - оишбка.


	 string_for_read_5.resize(0);   //Так как функция доавбляет в конец существующего "string_for_read", то если там уже есть какие то данные, а записать нужно к примеру с начала "string_for_read" - то зануляем его прежде, чем вызвать функцию.

	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_5  = ReadWrite_FromDisk.read__PartFile_to_StringBack<std::string>(path_string_ASCII,       File_Name_string_ASCII, string_for_read_5, string_for_read_5, pos_beg_5, pos_end_5);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_5  = ReadWrite_FromDisk.read__PartFile_to_StringBack<std::string>(path_string_UTF8, File_Name_string_UTF8, string_for_read_5, pos_beg_5, pos_end_5);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_5 = ReadWrite_FromDisk.read__PartFile_to_StringBack<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, string_for_read_5, pos_beg_5, pos_end_5);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_5  = ReadWrite_FromDisk.read__PartFile_to_StringBack<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, string_for_read_5, string_for_read_5, pos_beg_5, pos_end_5);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_5  = ReadWrite_FromDisk.read__PartFile_to_StringBack<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, string_for_read_5, string_for_read_5, pos_beg_5, pos_end_5);     //Вызываем.
	 
	 
     //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_5 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_5: OK" << std::endl;
		 std::cout << "string_for_read_5:" << string_for_read_5 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_5:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //------------------------------------------------------------------------------3:read__PartFile_to_StringBack:Конец--------------------------------------------------------------------------------------------



	 //-------------------------------------------------------------------------4:read__PartFile_to_StringBack:Начало--------------------------------------------------------------------------------------------

     //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в конец предооставленного ей "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 std::string string_for_read_7 = "Hello1";                //std::string - куда функция добавить считанные из файла данные.

	 const size_t pos_beg_7 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.                Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_7 = 4;                              //Позиция байта в файле, ДО которого включительно необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.  Выход за пределы файла не контролируется, в случае выхода - ошибка.



	 string_for_read_7.resize(0);   //Так как функция доавбляет в конец существующего "string_for_read", то если там уже есть какие то данные, а записать нужно к примеру с начала "string_for_read" - то зануляем его прежде, чем вызвать функцию.

	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_7  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::string>(Full_path_file_name_string_ASCII, string_for_read_7, pos_beg_7, pos_end_7);         //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_7  = ReadWrite_FromDisk.read__PartFile_to_StringBack<std::string>(Full_path_file_name_string_UTF8, string_for_read_7, pos_beg_7, pos_end_7);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_7 = ReadWrite_FromDisk.read__PartFile_to_StringBack<std::wstring>(Full_path_file_name_wstring_UTF16, string_for_read_7, pos_beg_7, pos_end_7);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_7  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::u16string>(Full_path_file_name_u16string_UTF16, string_for_read_7, pos_beg_7, pos_end_7);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_7  = ReadWrite_FromDisk.read__FullFile_to_StringBack<std::u32string>(Full_path_file_name_u32string_UTF32, string_for_read_7, pos_beg_7, pos_end_7);     //Вызываем.
	 
	 
     //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_7 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_7: OK" << std::endl;
		 std::cout << "string_for_read_7:" << string_for_read_7 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_7:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------4:read__PartFile_to_StringBack:Конец--------------------------------------------------------------------------------------------


	


	 //------------------------------------------------------------------------------5:read__PartFile_to_StringBack__OffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в конец предооставленного ей "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 std::string string_for_read_9 = "Hello1";              //std::string - куда функция добавить считанные данные.

	 const size_t pos_beg_9 = 5;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.               Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_offset_9 = 0;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.



	 string_for_read_9.resize(0);   //Так как функция доавбляет в конец существующего "string_for_read", то если там уже есть какие то данные, а записать нужно к примеру с начала "string_for_read" - то зануляем его прежде, чем вызвать функцию.

	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_9  = ReadWrite_FromDisk.read__PartFile_to_StringBack__OffsetEnd<std::string>(path_string_ASCII,       File_Name_string_ASCII, string_for_read_9, pos_beg_9, pos_end_offset_9);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_9  = ReadWrite_FromDisk.read__PartFile_to_StringBack__OffsetEnd<std::string>(path_string_UTF8, File_Name_string_UTF8, string_for_read_9, pos_beg_9, pos_end_offset_9);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_9 = ReadWrite_FromDisk.read__PartFile_to_StringBack__OffsetEnd<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, string_for_read_9, pos_beg_9, pos_end_offset_9);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_9  = ReadWrite_FromDisk.read__PartFile_to_StringBack__OffsetEnd<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, string_for_read_9, pos_beg_9, pos_end_offset_9);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_9  = ReadWrite_FromDisk.read__PartFile_to_StringBack__OffsetEnd<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, string_for_read_9, pos_beg_9, pos_end_offset_9);     //Вызываем.
	 
	 
	 //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_9 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_9: OK" << std::endl;
		 std::cout << "string_for_read_9:" << string_for_read_9 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_9:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //------------------------------------------------------------------------------5:read__PartFile_to_StringBack__OffsetEnd:Конец--------------------------------------------------------------------------------------------


	 //-------------------------------------------------------------------------6:read__PartFile_to_StringBack__OffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в конец предооставленного ей "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 std::string string_for_read_11 = "Hello1";                //std::string - куда функция добавить считанные из файла данные.

	 const size_t pos_beg_11 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.               Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_offset_11 = 1;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.




	 string_for_read_11.resize(0);   //Так как функция доавбляет в конец существующего "string_for_read", то если там уже есть какие то данные, а записать нужно к примеру с начала "string_for_read" - то зануляем его прежде, чем вызвать функцию.

	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_11  = ReadWrite_FromDisk.read__FullFile_to_StringBack__OffsetEnd<std::string>(Full_path_file_name_string_ASCII, string_for_read_11, pos_beg_11, pos_end_offset_11);         //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_11  = ReadWrite_FromDisk.read__PartFile_to_StringBack__OffsetEnd<std::string>(Full_path_file_name_string_UTF8, string_for_read_11, pos_beg_11, pos_end_offset_11);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_11 = ReadWrite_FromDisk.read__PartFile_to_StringBack__OffsetEnd<std::wstring>(Full_path_file_name_wstring_UTF16, string_for_read_11, pos_beg_11, pos_end_offset_11);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_11  = ReadWrite_FromDisk.read__FullFile_to_StringBack__OffsetEnd<std::u16string>(Full_path_file_name_u16string_UTF16, string_for_read_11, pos_beg_11, pos_end_offset_11);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_11  = ReadWrite_FromDisk.read__FullFile_to_StringBack__OffsetEnd<std::u32string>(Full_path_file_name_u32string_UTF32, string_for_read_11, pos_beg_11, pos_end_offset_11);     //Вызываем.
	 
	 
	 //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_11 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_11: OK" << std::endl;
		 std::cout << "string_for_read_11:" << string_for_read_11 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_11:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------6:read__PartFile_to_StringBack__OffsetEnd:Конец--------------------------------------------------------------------------------------------




	 //------------------------------------------------------------------------------7:read__PartFile_to_StringBack__DoubleOffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в конец предооставленного ей "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 std::string string_for_read_9_1 = "Hello1";              //std::string - куда функция добавить считанные данные.

	 const size_t BegPos_end_offset_9_1 = 2;                              //Смещение отнсоительно конечного байта в файле С которого включительно нужно начать читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.
	 const size_t EndPos_end_offset_9_1 = 1;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.



	 string_for_read_9_1.resize(0);   //Так как функция доавбляет в конец существующего "string_for_read", то если там уже есть какие то данные, а записать нужно к примеру с начала "string_for_read" - то зануляем его прежде, чем вызвать функцию.

	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_9_1  = ReadWrite_FromDisk.read__PartFile_to_StringBack__DoubleOffsetEnd<std::string>(path_string_ASCII,       File_Name_string_ASCII, string_for_read_9_1, BegPos_end_offset_9_1, EndPos_end_offset_9_1);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_12  = ReadWrite_FromDisk.read__PartFile_to_StringBack__DoubleOffsetEnd<std::string>(path_string_UTF8, File_Name_string_UTF8, string_for_read_9_1, BegPos_end_offset_9_1, EndPos_end_offset_9_1);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_9_1 = ReadWrite_FromDisk.read__PartFile_to_StringBack__DoubleOffsetEnd<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, string_for_read_9_1, BegPos_end_offset_9_1, EndPos_end_offset_9_1);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_9_1  = ReadWrite_FromDisk.read__PartFile_to_StringBack__DoubleOffsetEnd<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, string_for_read_9_1, BegPos_end_offset_9_1, EndPos_end_offset_9_1);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_9_1  = ReadWrite_FromDisk.read__PartFile_to_StringBack__DoubleOffsetEnd<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, string_for_read_9_1, BegPos_end_offset_9_1, EndPos_end_offset_9_1);     //Вызываем.
	 
      //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_9_1 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_9_1: OK" << std::endl;
		 std::cout << "string_for_read_9_1:" << string_for_read_9_1 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_9_1:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //------------------------------------------------------------------------------7:read__PartFile_to_StringBack__DoubleOffsetEnd:Конец--------------------------------------------------------------------------------------------


	
	 //-------------------------------------------------------------------------8:read__PartFile_to_StringBack__DoubleOffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в конец предооставленного ей "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 std::string string_for_read_11_1 = "Hello1";                //std::string - куда функция добавить считанные из файла данные.

	 const size_t BegPos_end_offset_11_1 = 2;                              //Смещение отнсоительно конечного байта в файле С которого включительно нужно начать читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.
	 const size_t EndPos_end_offset_11_1 = 1;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.




	 string_for_read_11_1.resize(0);   //Так как функция доавбляет в конец существующего "string_for_read", то если там уже есть какие то данные, а записать нужно к примеру с начала "string_for_read" - то зануляем его прежде, чем вызвать функцию.

	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_11_1  = ReadWrite_FromDisk.read__FullFile_to_StringBack__DoubleOffsetEnd<std::string>(Full_path_file_name_string_ASCII, string_for_read_11_1, BegPos_end_offset_11_1, EndPos_end_offset_11_1);         //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_11_1  = ReadWrite_FromDisk.read__PartFile_to_StringBack__DoubleOffsetEnd<std::string>(Full_path_file_name_string_UTF8, string_for_read_11_1, BegPos_end_offset_11_1, EndPos_end_offset_11_1);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_11_1 = ReadWrite_FromDisk.read__PartFile_to_StringBack__DoubleOffsetEnd<std::wstring>(Full_path_file_name_wstring_UTF16, string_for_read_11_1, BegPos_end_offset_11_1, EndPos_end_offset_11_1);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_11_1  = ReadWrite_FromDisk.read__FullFile_to_StringBack__DoubleOffsetEnd<std::u16string>(Full_path_file_name_u16string_UTF16, string_for_read_11_1, BegPos_end_offset_11_1, EndPos_end_offset_11_1);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_11_1  = ReadWrite_FromDisk.read__FullFile_to_StringBack__DoubleOffsetEnd<std::u32string>(Full_path_file_name_u32string_UTF32, string_for_read_11_1, BegPos_end_offset_11_1, EndPos_end_offset_11_1);     //Вызываем.
	
	  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_11_1 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_11_1: OK" << std::endl;
		 std::cout << "string_for_read_11_1:" << string_for_read_11_1 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_11_1:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------8:read__PartFile_to_StringBack__DoubleOffsetEnd:Конец--------------------------------------------------------------------------------------------





	 //-------------------------------------------------------------------------9:read__FullFile_to_FixSizeCharPointer:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают все содержимое файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 std::string string_for_read_13; string_for_read_13.resize(100);   //балванка

	 char* char_p_13 = &string_for_read_13[6];             //Указатель который передается в функцию, куда функция считывает все содержимое файлы.
	

	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_13  = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::string>(path_string_ASCII,       File_Name_string_ASCII, char_p_13);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_13  = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::string>(path_string_UTF8, File_Name_string_UTF8, char_p_13);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_13 = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_13);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_13  = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, char_p_13);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_13  = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, char_p_13);     //Вызываем.
	 
	  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_13 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_13: OK" << std::endl;
		 std::cout << "char_p_13:" << char_p_13 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_13:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------9:read__FullFile_to_FixSizeCharPointer:Конец--------------------------------------------------------------------------------------------


	 //-------------------------------------------------------------------------10:read__FullFile_to_FixSizeCharPointer:Начало--------------------------------------------------------------------------------------------

	//Это шаблонная функция - считывают все содержимое файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 std::string string_for_read_15; string_for_read_15.resize(100);   //балванка

	 char* char_p_15 = &string_for_read_15[6];             //Указатель который передается в функцию, куда функция считывает все содержимое файлы.



	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_15  = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::string>(Full_path_file_name_string_ASCII, char_p_15);         //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_15  = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::string>(Full_path_file_name_string_UTF8, char_p_15);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_15 = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::wstring>(Full_path_file_name_wstring_UTF16, char_p_15);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_15  = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::u16string>(Full_path_file_name_u16string_UTF16, char_p_15);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_15  = ReadWrite_FromDisk.read__FullFile_to_FixSizeCharPointer<std::u32string>(Full_path_file_name_u32string_UTF32, char_p_15);     //Вызываем.
	 
	  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_15 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_15: OK" << std::endl;
		 std::cout << "char_p_15:" << char_p_15 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_15:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------10:read__FullFile_to_FixSizeCharPointer:Конец--------------------------------------------------------------------------------------------




	 //-------------------------------------------------------------------------11:read__PartFile_to_FixSizeCharPointer:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 std::string string_for_read_17; string_for_read_17.resize(100);   //балванка

	 char* char_p_17 = &string_for_read_17[6];             //Указатель который передается в функцию, куда функция считывает все содержимое файлы.

	 const size_t pos_beg_17 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.                  Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_17 = 4;                              //Позиция байта в файле, ДО которого включительно необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.    Выход за пределы файла не контролируется, в случае выхода - ошибка.




	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_17  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::string>(path_string_ASCII,       File_Name_string_ASCII, char_p_17, pos_beg_17, pos_end_17);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_17  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::string>(path_string_UTF8, File_Name_string_UTF8, char_p_17, pos_beg_17, pos_end_17);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_17 = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_17, pos_beg_17, pos_end_17);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_17  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, char_p_17, pos_beg_17, pos_end_17);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_17  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, char_p_17, pos_beg_17, pos_end_17);     //Вызываем.
	 
	 //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_17 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_17: OK" << std::endl;
		 std::cout << "char_p_17:" << char_p_17 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_17:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------11:read__PartFile_to_FixSizeCharPointer:Конец--------------------------------------------------------------------------------------------


	

	 //-------------------------------------------------------------------------12:read__PartFile_to_FixSizeCharPointer:Начало--------------------------------------------------------------------------------------------
	 
	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.//Это шаблонная функция - считывают все содержимое файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 std::string string_for_read_19; string_for_read_19.resize(100);   //балванка

	 char* char_p_19 = &string_for_read_19[6];             //Указатель который передается в функцию, куда функция считывает все содержимое файлы.

	 const size_t pos_beg_19 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.                  Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_19 = 4;                              //Позиция байта в файле, ДО которого включительно необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.    Выход за пределы файла не контролируется, в случае выхода - ошибка.



	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_19  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::string>(Full_path_file_name_string_ASCII, char_p_19, pos_beg_19, pos_end_19);         //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_19  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::string>(Full_path_file_name_string_UTF8, char_p_19, pos_beg_19, pos_end_19);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_19 = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::wstring>(Full_path_file_name_wstring_UTF16, char_p_19, pos_beg_19, pos_end_19);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_19  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::u16string>(Full_path_file_name_u16string_UTF16, char_p_19, pos_beg_19, pos_end_19);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_19  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer<std::u32string>(Full_path_file_name_u32string_UTF32, char_p_19, pos_beg_19, pos_end_19);     //Вызываем.
	 
	 
	  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_19 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_19: OK" << std::endl;
		 std::cout << "char_p_19:" << char_p_19 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_19:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------12:read__PartFile_to_FixSizeCharPointer:Конец--------------------------------------------------------------------------------------------


	



	 //-------------------------------------------------------------------------13:read__PartFile_to_FixSizeCharPointer__OffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 std::string string_for_read_21; string_for_read_21.resize(100);   //балванка

	 char* char_p_21 = &string_for_read_21[6];             //Указатель который передается в функцию, куда функция считывает все содержимое файлы.

	 const size_t pos_beg_21 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.               Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_offset_21 = 1;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.

	 size_t read_size_21 = 0;                                 //Сюда функцию поместить кол-во считанных байт.



	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_21  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::string>(path_string_ASCII,       File_Name_string_ASCII, char_p_21, pos_beg_21, pos_end_offset_21, read_size_21);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_21  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::string>(path_string_UTF8, File_Name_string_UTF8,  char_p_21, pos_beg_21, pos_end_offset_21, read_size_21);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_21 = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_21, pos_beg_21, pos_end_offset_21, read_size_21);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_21  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, char_p_21, pos_beg_21, pos_end_offset_21, read_size_21);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_21  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, char_p_21, pos_beg_21, pos_end_offset_21, read_size_21);     //Вызываем.
	 
		 //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_21 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_21: OK" << std::endl;
		 std::cout << "char_p_21:" << char_p_21 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_21:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------13:read__PartFile_to_FixSizeCharPointer__OffsetEnd:Конец--------------------------------------------------------------------------------------------



	 //-------------------------------------------------------------------------14:read__PartFile_to_FixSizeCharPointer__OffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.//Это шаблонная функция - считывают все содержимое файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 std::string string_for_read_23; string_for_read_23.resize(100);   //балванка

	 char* char_p_23 = &string_for_read_23[6];             //Указатель который передается в функцию, куда функция считывает все содержимое файлы.

	 const size_t pos_beg_23 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.               Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_offset_23 = 1;                     //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.

	 size_t read_size_23 = 0;                                 //Сюда функцию поместить кол-во считанных байт.




	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_23  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::string>(Full_path_file_name_string_ASCII, char_p_23, pos_end_offset_23, read_size_23);         //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_23  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::string>(Full_path_file_name_string_UTF8, char_p_23, pos_beg_23, pos_end_offset_23, read_size_23);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_23 = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::wstring>(Full_path_file_name_wstring_UTF16, char_p_23, pos_beg_23, pos_end_offset_23, read_size_23);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_23  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::u16string>(Full_path_file_name_u16string_UTF16, char_p_23, pos_end_offset_23, read_size_23);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_23  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__OffsetEnd<std::u32string>(Full_path_file_name_u32string_UTF32, char_p_23, pos_end_offset_23, read_size_23);     //Вызываем.
	
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_23 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_23: OK" << std::endl;
		 std::cout << "char_p_23:" << char_p_23 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_23:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------14:read__PartFile_to_FixSizeCharPointer:Конец--------------------------------------------------------------------------------------------






	 //-------------------------------------------------------------------------15:read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 std::string string_for_read_21_1; string_for_read_21_1.resize(100);   //балванка

	 char* char_p_21_1 = &string_for_read_21_1[6];             //Указатель который передается в функцию, куда функция считывает все содержимое файлы.

	 const size_t BegPos_end_offset_21_1 = 2;                              //Смещение отнсоительно конечного байта в файле С которого включительно нужно начать читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.
	 const size_t EndPos_end_offset_21_1 = 1;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.

	 size_t read_size_21_1 = 0;                                 //Сюда функцию поместить кол-во считанных байт.



	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_21_1  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::string>(path_string_ASCII,       File_Name_string_ASCII, char_p_21_1, pos_beg_21_1, EndPos_end_offset_21_1, read_size_21_1);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_21_1  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::string>(path_string_UTF8, File_Name_string_UTF8, char_p_21_1, BegPos_end_offset_21_1, EndPos_end_offset_21_1, read_size_21_1);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_21_1 = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_21_1, BegPos_end_offset_21_1, EndPos_end_offset_21_1, read_size_21_1);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_21_1  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, char_p_21_1, pos_beg_21_1, EndPos_end_offset_21_1, read_size_21_1);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_21_1  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, char_p_21_1, pos_beg_21_1, pEndPos_end_offset_21_1, read_size_21_1);     //Вызываем.
	 
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_21_1 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_21_1: OK" << std::endl;
		 std::cout << "char_p_21_1:" << char_p_21_1 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_21_1:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------15:read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd:Конец--------------------------------------------------------------------------------------------



	 //-------------------------------------------------------------------------16:read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.//Это шаблонная функция - считывают все содержимое файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 std::string string_for_read_23_1; string_for_read_23_1.resize(100);   //балванка

	 char* char_p_23_1 = &string_for_read_23_1[6];             //Указатель который передается в функцию, куда функция считывает все содержимое файлы.

	 const size_t BegPos_end_offset_23_1 = 2;                              //Смещение отнсоительно конечного байта в файле С которого включительно нужно начать читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.
	 const size_t EndPos_end_offset_23_1 = 1;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.

	 size_t read_size_23_1 = 0;                                 //Сюда функцию поместить кол-во считанных байт.




	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_23_1  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::string>(Full_path_file_name_string_ASCII, char_p_23_1, BegPos_end_offset_23_1, EndPos_end_offset_23_1, read_size_23_1);         //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_23_1  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::string>(Full_path_file_name_string_UTF8,  char_p_23_1, BegPos_end_offset_23_1, EndPos_end_offset_23_1, read_size_23_1);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_23_1 = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::wstring>(Full_path_file_name_wstring_UTF16, char_p_23_1, BegPos_end_offset_23_1, EndPos_end_offset_23_1, read_size_23_1);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_23_1  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::u16string>(Full_path_file_name_u16string_UTF16, char_p_23_1, BegPos_end_offset_23_1, EndPos_end_offset_23_1, read_size_23_1);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_23_1  = ReadWrite_FromDisk.read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd<std::u32string>(Full_path_file_name_u32string_UTF32, char_p_23_1, BegPos_end_offset_23_1, EndPos_end_offset_23_1, read_size_23_1);     //Вызываем.
	
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_23_1 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_23_1: OK" << std::endl;
		 std::cout << "char_p_23_1:" << char_p_23_1 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_23_1:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------16:read__PartFile_to_FixSizeCharPointer:Конец--------------------------------------------------------------------------------------------






	 //-------------------------------------------------------------------------17:read__FullFile_to_DynamicRawPointer:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают все содержимое файла и добавляет в предоставленный указатель. Функция принимает адресс пустого указателя и выделяет память в сооветтвии с прочитанными из файла данными.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 char* char_p_25;             //Указатель, адресс которого передаем в функцию, которая выделить память по этому указател. Не забываем, когда нужно освобождать память черех delete[]. Хотя нахрен сырое выделение памяти не нужно, но пусть будет.
	
	 size_t read_size_25 = 0;                                 //Сюда функцию поместить кол-во считанных байт.



	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_25  = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::string>(path_string_ASCII,       File_Name_string_ASCII, &char_p_25, read_size_25);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_25  = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::string>(path_string_UTF8, File_Name_string_UTF8,  &char_p_25, read_size_25);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_25 = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, &char_p_25, read_size_25);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_25  = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, &char_p_25, read_size_25);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_25  = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, &char_p_25, read_size_25);     //Вызываем.
	 
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_25 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_25: OK" << std::endl;
		 std::cout << "char_p_25:" << char_p_25 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_25:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------17:read__FullFile_to_DynamicRawPointer:Конец--------------------------------------------------------------------------------------------



	 //-------------------------------------------------------------------------18:read__FullFile_to_DynamicRawPointer:Начало--------------------------------------------------------------------------------------------

	//Это шаблонная функция - считывают все содержимое файла и добавляет в предоставленный указатель - размер ресурса по указателю должен соовтетвовать размеру считываемых данных из файла, иначе соответвенно ошибка.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 char* char_p_27;             //Указатель, адресс которого передаем в функцию, которая выделить память по этому указател. Не забываем, когда нужно освобождать память черех delete[]. Хотя нахрен сырое выделение памяти не нужно, но пусть будет.

	 size_t read_size_27 = 0;                                 //Сюда функцию поместить кол-во считанных байт.



	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_27  = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::string>(Full_path_file_name_string_ASCII, &char_p_27, read_size_27);         //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_27  = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::string>(Full_path_file_name_string_UTF8,  &char_p_27, read_size_27);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_27 = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::wstring>(Full_path_file_name_wstring_UTF16, &char_p_27, read_size_27);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_27  = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::u16string>(Full_path_file_name_u16string_UTF16, &char_p_27, read_size_27);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_27  = ReadWrite_FromDisk.read__FullFile_to_DynamicRawPointer<std::u32string>(Full_path_file_name_u32string_UTF32, &char_p_27, read_size_27);     //Вызываем.
	
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_27 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_27: OK" << std::endl;
		 std::cout << "char_p_27:" << char_p_27 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_27:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------18:read__FullFile_to_DynamicRawPointer:Конец--------------------------------------------------------------------------------------------


	

	 //-------------------------------------------------------------------------19:read__PartFile_to_DynamicRawPointer:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель. Функция принимает адресс пустого указателя и выделяет память в сооветтвии с прочитанными из файла данными.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 char* char_p_29;             //Указатель, адресс которого передаем в функцию, которая выделить память по этому указател. Не забываем, когда нужно освобождать память черех delete[]. Хотя нахрен сырое выделение памяти не нужно, но пусть будет.

	 const size_t pos_beg_29 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.                  Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_29 = 4;                              //Позиция байта в файле, ДО которого включительно необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.    Выход за пределы файла не контролируется, в случае выхода - ошибка.



	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_29  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::string>(path_string_ASCII,       File_Name_string_ASCII, &char_p_29, pos_beg_29, pos_end_29);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_29  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::string>(path_string_UTF8, File_Name_string_UTF8,  &char_p_29, pos_beg_29, pos_end_29);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_29 = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, &char_p_29, pos_beg_29, pos_end_29);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_29  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, &char_p_29, pos_beg_29, pos_end_29);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_29  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, &char_p_29, pos_beg_29, pos_end_29);     //Вызываем.
	
	 
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_29 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_29: OK" << std::endl;
		 std::cout << "char_p_29:" << char_p_29 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_29:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------19:read__PartFile_to_DynamicRawPointer:Конец--------------------------------------------------------------------------------------------


	

	 //-------------------------------------------------------------------------20:read__PartFile_to_DynamicRawPointer:Начало--------------------------------------------------------------------------------------------

	//Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель. Функция принимает адресс пустого указателя и выделяет память в сооветтвии с прочитанными из файла данными.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 char* char_p_31;             //Указатель, адресс которого передаем в функцию, которая выделить память по этому указател. Не забываем, когда нужно освобождать память черех delete[]. Хотя нахрен сырое выделение памяти не нужно, но пусть будет.

	 const size_t pos_beg_31 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.                  Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_31 = 4;                              //Позиция байта в файле, ДО которого включительно необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.    Выход за пределы файла не контролируется, в случае выхода - ошибка.



	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_31  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::string>(Full_path_file_name_string_ASCII, , &char_p_31, pos_beg_31, pos_end_31);         //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_31  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::string>(Full_path_file_name_string_UTF8, &char_p_31, pos_beg_31, pos_end_31);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_31 = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::wstring>(Full_path_file_name_wstring_UTF16, &char_p_31, pos_beg_31, pos_end_31);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_31  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::u16string>(Full_path_file_name_u16string_UTF16, , &char_p_31, pos_beg_31, pos_end_31);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_31  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer<std::u32string>(Full_path_file_name_u32string_UTF32, , &char_p_31, pos_beg_31, pos_end_31);     //Вызываем.
	
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_31 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_31: OK" << std::endl;
		 std::cout << "char_p_31:" << char_p_31 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_31:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------20:read__PartFile_to_DynamicRawPointer:Конец--------------------------------------------------------------------------------------------


	


	 //-------------------------------------------------------------------------21:read__PartFile_to_DynamicRawPointer__OffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель. Функция принимает адресс пустого указателя и выделяет память в сооветтвии с прочитанными из файла данными.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 char* char_p_33;             //Указатель, адресс которого передаем в функцию, которая выделить память по этому указател. Не забываем, когда нужно освобождать память черех delete[]. Хотя нахрен сырое выделение памяти не нужно, но пусть будет.

	 const size_t pos_beg_33 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.               Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_offset_33 = 1;                     //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.

	 size_t read_size_33 = 0;                                 //Сюда функцию поместить кол-во считанных байт.




	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_33  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::string>(path_string_ASCII,       File_Name_string_ASCII, &char_p_33, pos_beg_33, pos_end_offset_33, read_size_33);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_33  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::string>(path_string_UTF8, File_Name_string_UTF8,  &char_p_33, pos_beg_33, pos_end_offset_33, read_size_33);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_33 = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, &char_p_33, pos_beg_33, pos_end_offset_33, read_size_33);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_33  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, &char_p_33, pos_beg_33, pos_end_offset_33, read_size_33);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_33  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, &char_p_33, pos_beg_33, pos_end_offset_33, read_size_33);     //Вызываем.
	
	 
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_33 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_33: OK" << std::endl;
		 std::cout << "char_p_33:" << char_p_33 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_33:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------21:read__PartFile_to_DynamicRawPointer__OffsetEnd:Конец--------------------------------------------------------------------------------------------




	 //-------------------------------------------------------------------------22:read__PartFile_to_DynamicRawPointer__OffsetEnd:Начало--------------------------------------------------------------------------------------------

	//Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель. Функция принимает адресс пустого указателя и выделяет память в сооветтвии с прочитанными из файла данными.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 char* char_p_35;             //Указатель, адресс которого передаем в функцию, которая выделить память по этому указател. Не забываем, когда нужно освобождать память черех delete[]. Хотя нахрен сырое выделение памяти не нужно, но пусть будет.

	 const size_t pos_beg_35 = 1;                              //Позиция байта в файле, С которого необходимо считать данные. Нумерация стандартная 0 - это первый байт, 1 - второй байт.               Выход за пределы файла не контролируется, в случае выхода - ошибка.
	 const size_t pos_end_offset_35 = 1;                     //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.

	 size_t read_size_35 = 0;                                 //Сюда функцию поместить кол-во считанных байт.




	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_35  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::string>(Full_path_file_name_string_ASCII, &char_p_35, pos_beg_35, pos_end_offset_35, read_size_35);         //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_35  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::string>(Full_path_file_name_string_UTF8,  &char_p_35, pos_beg_35, pos_end_offset_35, read_size_35);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_35 = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::wstring>(Full_path_file_name_wstring_UTF16, &char_p_35, pos_beg_35, pos_end_offset_35, read_size_35);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_35  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::u16string>(Full_path_file_name_u16string_UTF16, &char_p_35, pos_beg_35, pos_end_offset_35, read_size_35);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_35  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__OffsetEnd<std::u32string>(Full_path_file_name_u32string_UTF32, &char_p_35, pos_beg_35, pos_end_offset_35, read_size_35);     //Вызываем.
	 
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_35 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_35: OK" << std::endl;
		 std::cout << "char_p_35:" << char_p_35 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_35:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------22:read__PartFile_to_DynamicRawPointer__OffsetEnd:Конец--------------------------------------------------------------------------------------------


	


	 //-------------------------------------------------------------------------23:read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель. Функция принимает адресс пустого указателя и выделяет память в сооветтвии с прочитанными из файла данными.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. Путь и имя файла передается раздельно.


	 //---------------------------------------------------------------
	 char* char_p_33_1;             //Указатель, адресс которого передаем в функцию, которая выделить память по этому указател. Не забываем, когда нужно освобождать память черех delete[]. Хотя нахрен сырое выделение памяти не нужно, но пусть будет.

	 const size_t BegPos_end_offset_33_1 = 2;                              //Смещение отнсоительно конечного байта в файле С которого включительно нужно начать читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.
	 const size_t EndPos_end_offset_33_1 = 1;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.

	 size_t read_size_33_1 = 0;                                 //Сюда функцию поместить кол-во считанных байт.




	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_33_1  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::string>(path_string_ASCII,       File_Name_string_ASCII, &char_p_33_1, BegPos_end_offset_33_1, EndPos_end_offset_33_1, read_size_33_1);        //Вызываем.
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_33_1  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::string>(path_string_UTF8, File_Name_string_UTF8,  &char_p_33_1, BegPos_end_offset_33_1, EndPos_end_offset_33_1, read_size_33_1);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_33_1 = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, &char_p_33_1, BegPos_end_offset_33_1, EndPos_end_offset_33_1, read_size_33_1);       //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_33_1  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::u16string>(path_u16string_UTF16, File_Name_u16string_UTF16, &char_p_33_1, BegPos_end_offset_33_1, EndPos_end_offset_33_1, read_size_33_1);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_33_1  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::u32string>(path_u32string_UTF32, File_Name_u32string_UTF32, &char_p_33_1, BegPos_end_offset_33_1, EndPos_end_offset_33_1, read_size_33_1);     //Вызываем.
	
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_33_1 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_33_1: OK" << std::endl;
		 std::cout << "char_p_33_1:" << char_p_33_1 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_33_1:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------23:read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd:Конец--------------------------------------------------------------------------------------------


	

	 //-------------------------------------------------------------------------24:read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd:Начало--------------------------------------------------------------------------------------------

	//Это шаблонная функция - считывают указанный диапазон из файла и добавляет в предоставленный указатель. Функция принимает адресс пустого указателя и выделяет память в сооветтвии с прочитанными из файла данными.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 


	 //---------------------------------------------------------------
	 char* char_p_35_1;             //Указатель, адресс которого передаем в функцию, которая выделить память по этому указател. Не забываем, когда нужно освобождать память черех delete[]. Хотя нахрен сырое выделение памяти не нужно, но пусть будет.

	 const size_t BegPos_end_offset_35_1 = 2;                              //Смещение отнсоительно конечного байта в файле С которого включительно нужно начать читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.
	 const size_t EndPos_end_offset_35_1 = 1;                    //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте, +1 - смещение на предпослденем и так далее. Смещение указывается ТОЛЬКО В ПОЛОЖИТЕЛЬНОМ ЗНАЧЕНИИ и СМЕЩЕНИЕ ПРОИСОДИТ ВЛЕВО, ТО ЕСТЬ К НАЧАЛУ ФАЙЛА ОТ КОНЕЧНО БАЙТА НА УКАЗАННОЕ ЗНАЧЕНИЕ.

	 size_t read_size_35_1 = 0;                                 //Сюда функцию поместить кол-во считанных байт.




	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_35_1  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::string>(Full_path_file_name_string_ASCII, &char_p_35_1, BegPos_end_offset_35_1, EndPos_end_offset_35_1, read_size_35_1);         //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_35_1  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::string>(Full_path_file_name_string_UTF8, &char_p_35_1, BegPos_end_offset_35_1, EndPos_end_offset_35_1, read_size_35_1);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_35_1 = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::wstring>(Full_path_file_name_wstring_UTF16, &char_p_35_1, BegPos_end_offset_35_1, EndPos_end_offset_35_1, read_size_35_1);           //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_35_1  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::u16string>(Full_path_file_name_u16string_UTF16, &char_p_35_1, BegPos_end_offset_35_1, EndPos_end_offset_35_1, read_size_35_1);     //Вызываем.
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_35_1  = ReadWrite_FromDisk.read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd<std::u32string>(Full_path_file_name_u32string_UTF32, &char_p_35_1, BegPos_end_offset_35_1, EndPos_end_offset_35_1, read_size_35_1);     //Вызываем.
	 
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	 //---------------------------------------------------------------
	 if (result_35_1 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	 {
		 std::cout << "Result_35_1: OK" << std::endl;
		 std::cout << "char_p_35_1:" << char_p_35_1 << std::endl;  //Выводим прочитанные данные.
	 }
	 else
	 {
		 std::cout << "Result_35_1:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		 return -1;
	 }
	 //---------------------------------------------------------------


	 //-------------------------------------------------------------------------24:read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd:Конец--------------------------------------------------------------------------------------------





	 //-------------------------------------------------------------------------------------------25:write__to_PreClear_File:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - записывает данные из переданного указателя с предварительным обнулением всей информации в файле.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 



	 //---------------------------------------------------------------

	 std::string string_for_write_37 = u8"东Hello1";   //Балванка

	 char* char_p_for_write_37 = &string_for_write_37[2];         //Указатель на данные которые нужно записать в файл в кол-ве "ButeSize_for_write__37".

	 const size_t ButeSize_for_write__37 = 5;                     //Кол-во байт, который нужно записать в файл по указателю "char_p_for_write_37".


	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_37 = ReadWrite_FromDisk.write__to_PreClear_File<std::string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_37, ButeSize_for_write__37);
	  //const ReadWrite_FromDisk_Cpp17__class::result_flag result_37  = ReadWrite_FromDisk.write__to_PreClear_File<std::string>(path_string_UTF8, File_Name_string_UTF8, char_p_for_write_37, ButeSize_for_write__37);                //Вызываем.
	 const ReadWrite_FromDisk_Cpp17__class::result_flag result_37 = ReadWrite_FromDisk.write__to_PreClear_File<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_37, ButeSize_for_write__37);
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_37 = ReadWrite_FromDisk.write__to_PreClear_File<std::u16string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_37, ButeSize_for_write__37);
     //const ReadWrite_FromDisk_Cpp17__class::result_flag result_37 = ReadWrite_FromDisk.write__to_PreClear_File<std::u32string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_37, ButeSize_for_write__37);
	 
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	 //---------------------------------------------------------------


	//---------------------------------------------------------------
	if (result_37 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		std::cout << "Result_37: OK" << std::endl;
	}
	else
	{
		std::cout << "Result_37:" << ReadWrite_FromDisk.get__NameError() << std::endl;

	 return -1;
	}
	 //---------------------------------------------------------------



	 //-------------------------------------------------------------------------------------------25:write__to_PreClear_File:Конец--------------------------------------------------------------------------------------------





	 //-------------------------------------------------------------------------------------------26:write__to_PreClear_File:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - записывает данные из переданного указателя с предварительным обнулением всей информации в файле.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 



	 //---------------------------------------------------------------

	std::string string_for_write_39 = u8"东Hello1";   //Балванка

	char* char_p_for_write_39 = &string_for_write_39[2];         //Указатель на данные которые нужно записать в файл в кол-ве "ButeSize_for_write__39".

	const size_t ButeSize_for_write__39 = 5;                     //Кол-во байт, который нужно записать в файл по указателю "char_p_for_write_39".


	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_39 = ReadWrite_FromDisk.write__to_PreClear_File<std::string>(Full_path_file_name_wstring_UTF16, char_p_for_write_39, ButeSize_for_write__39);
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_39  = ReadWrite_FromDisk.write__to_PreClear_File<std::string>(Full_path_file_name_string_UTF8, char_p_for_write_39, ButeSize_for_write__39);                //Вызываем.
	const ReadWrite_FromDisk_Cpp17__class::result_flag result_39 = ReadWrite_FromDisk.write__to_PreClear_File<std::wstring>(Full_path_file_name_wstring_UTF16, char_p_for_write_39, ButeSize_for_write__39);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_39 = ReadWrite_FromDisk.write__to_PreClear_File<std::u16string>(Full_path_file_name_wstring_UTF16, char_p_for_write_39, ButeSize_for_write__39);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_39 = ReadWrite_FromDisk.write__to_PreClear_File<std::u32string>(Full_path_file_name_wstring_UTF16, char_p_for_write_39, ButeSize_for_write__39);
	
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//---------------------------------------------------------------


   //---------------------------------------------------------------
	if (result_39 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		std::cout << "Result_39: OK" << std::endl;
	}
	else
	{
		std::cout << "Result_39:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		return -1;
	}
	//---------------------------------------------------------------



	//-------------------------------------------------------------------------------------------26:write__to_PreClear_File:Конец--------------------------------------------------------------------------------------------






	 //-------------------------------------------------------------------------------------------27:write__to_SelectPos_File:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - записывает данные из переданного указателя в указанное положение в файле, без какого либо обнуления данных файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 



	 //---------------------------------------------------------------

	std::string string_for_write_41 = u8"东Hello1";   //Балванка

	char* char_p_for_write_41 = &string_for_write_41[2];         //Указатель на данные которые нужно записать в файл в кол-ве "ButeSize_for_write__41".

	const size_t ButeSize_for_write__41 = 5;                     //Кол-во байт, который нужно записать в файл по указателю "char_p_for_write_41".

	const size_t PosBegInFile_to_write_41 = 2;                      //Номер байта в файле с которого включительно функция запишут данные из указателя "char_p_for_write_41" в кол-ве "ButeSize_for_write__41" байт.


	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_41 = ReadWrite_FromDisk.write__to_SelectPos_File<std::string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_41, ButeSize_for_write__41, PosBegInFile_to_write_41);
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_41  = ReadWrite_FromDisk.write__to_SelectPos_File<std::string>(path_string_UTF8, File_Name_string_UTF8, char_p_for_write_41, ButeSize_for_write__41, PosBegInFile_to_write_41);                //Вызываем.
	const ReadWrite_FromDisk_Cpp17__class::result_flag result_41 = ReadWrite_FromDisk.write__to_SelectPos_File<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_41, ButeSize_for_write__41, PosBegInFile_to_write_41);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_41 = ReadWrite_FromDisk.write__to_SelectPos_File<std::u16string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_41, ButeSize_for_write__41, PosBegInFile_to_write_41);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_41 = ReadWrite_FromDisk.write__to_SelectPos_File<std::u32string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_41, ButeSize_for_write__41, PosBegInFile_to_write_41);
	
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//---------------------------------------------------------------


   //---------------------------------------------------------------
	if (result_41 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		std::cout << "Result_41: OK" << std::endl;
	}
	else
	{
		std::cout << "Result_41:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		return -1;
	}
	//---------------------------------------------------------------



	//-------------------------------------------------------------------------------------------27:write__to_SelectPos_File:Конец--------------------------------------------------------------------------------------------





	 //-------------------------------------------------------------------------------------------28:write__to_SelectPos_File:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - записывает данные из переданного указателя в указанное положение в файле, без какого либо обнуления данных файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 



	 //---------------------------------------------------------------

	std::string string_for_write_43 = u8"东Hello1";   //Балванка

	char* char_p_for_write_43 = &string_for_write_43[2];         //Указатель на данные которые нужно записать в файл в кол-ве "ButeSize_for_write__43".

	const size_t ButeSize_for_write__43 = 5;                     //Кол-во байт, который нужно записать в файл по указателю "char_p_for_write_43".

	const size_t PosBegInFile_to_write_43 = 2;                      //Номер байта в файле с которого включительно функция запишут данные из указателя "char_p_for_write_41" в кол-ве "ButeSize_for_write__41" байт.


	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_43 = ReadWrite_FromDisk.write__to_SelectPos_File<std::string>(Full_path_file_name_wstring_UTF16, char_p_for_write_43, ButeSize_for_write__43, PosBegInFile_to_write_43);
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_43  = ReadWrite_FromDisk.write__to_SelectPos_File<std::string>(Full_path_file_name_string_UTF8, char_p_for_write_43, ButeSize_for_write__43, PosBegInFile_to_write_43);                //Вызываем.
	const ReadWrite_FromDisk_Cpp17__class::result_flag result_43 = ReadWrite_FromDisk.write__to_SelectPos_File<std::wstring>(Full_path_file_name_wstring_UTF16, char_p_for_write_43, ButeSize_for_write__43, PosBegInFile_to_write_43);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_43 = ReadWrite_FromDisk.write__to_SelectPos_File<std::u16string>(Full_path_file_name_wstring_UTF16, char_p_for_write_43, ButeSize_for_write__43, PosBegInFile_to_write_43);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_43 = ReadWrite_FromDisk.write__to_SelectPos_File<std::u32string>(Full_path_file_name_wstring_UTF16, char_p_for_write_43, ButeSize_for_write__43, PosBegInFile_to_write_43);
	
		  //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//---------------------------------------------------------------


   //---------------------------------------------------------------
	if (result_43 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		std::cout << "Result_43: OK" << std::endl;
	}
	else
	{
		std::cout << "Result_43:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		return -1;
	}
	//---------------------------------------------------------------



	//-------------------------------------------------------------------------------------------28:write__to_SelectPos_File:Конец--------------------------------------------------------------------------------------------





	 //-------------------------------------------------------------------------------------------29:write__to_SelectPos_File__OffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - записывает данные из переданного указателя в указанное положение в файле, без какого либо обнуления данных файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 



	 //---------------------------------------------------------------

	std::string string_for_write_45 = u8"东Hello1";   //Балванка

	const char* char_p_for_write_45 = &string_for_write_45[2];         //Указатель на данные которые нужно записать в файл в кол-ве "ButeSize_for_write__45".

	const size_t ButeSize_for_write__45 = 5;                     //Кол-во байт, который нужно записать в файл по указателю "char_p_for_write_45".

	const size_t PosEndOffsetFile_to_write_45 = 1;               //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте. Положительное значение смещает курсор ВПРАВО от конечного байта, Отрицательное значение смещает ВЛЕВО от конечного байта, то есть к началу файла.

               

	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_45 = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_45, ButeSize_for_write__45, PosEndOffsetFile_to_write_45);
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_45  = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::string>(path_string_UTF8, File_Name_string_UTF8, char_p_for_write_45, ButeSize_for_write__45, PosEndOffsetFile_to_write_4);                //Вызываем.
	const ReadWrite_FromDisk_Cpp17__class::result_flag result_45 = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::wstring>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_45, ButeSize_for_write__45, PosEndOffsetFile_to_write_45);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_45 = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::u16string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_45, ButeSize_for_write__45, PosEndOffsetFile_to_write_45);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_45 = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::u32string>(path_wstring_UTF16, File_Name_wstring_UTF16, char_p_for_write_45, ButeSize_for_write__45, PosEndOffsetFile_to_write_45);
	//---------------------------------------------------------------


   //---------------------------------------------------------------
	if (result_45 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		std::cout << "Result_45: OK" << std::endl;
	}
	else
	{
		std::cout << "Result_45:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		return -1;
	}
	
	//Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//---------------------------------------------------------------



	//-------------------------------------------------------------------------------------------29:write__to_SelectPos_File__OffsetEnd:Конец--------------------------------------------------------------------------------------------





	 //-------------------------------------------------------------------------------------------30:write__to_SelectPos_File__OffsetEnd:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - записывает данные из переданного указателя в указанное положение в файле, без какого либо обнуления данных файла.
	 //В качестве пути принимает кодировки: ASCII, UTF-16, UTF-16(wstring), UTF-32 и UTF-8 и соответвующий тип в качестве шаблона. 



	 //---------------------------------------------------------------

	std::string string_for_write_47 = u8"东Hello1";   //Балванка

	char* char_p_for_write_47 = &string_for_write_47[2];         //Указатель на данные которые нужно записать в файл в кол-ве "ButeSize_for_write__47".

	const size_t ButeSize_for_write__47 = 5;                     //Кол-во байт, который нужно записать в файл по указателю "char_p_for_write_47".

	const size_t PosEndOffsetFile_to_write_47 = 1;               //Смещение отнсоительно конечного байта в файле ДО которого включительно нужно читать. Выход за пределы файла не контролируется, в случае выхода - оишбка. То есть 0 - значит позиция на последнем байте. Положительное значение смещает курсор ВПРАВО от конечного байта, Отрицательное значение смещает ВЛЕВО от конечного байта, то есть к началу файла.




	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_47 = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::string>(Full_path_file_name_wstring_UTF16, char_p_for_write_47, ButeSize_for_write__47, PosEndOffsetFile_to_write_47);
	 //const ReadWrite_FromDisk_Cpp17__class::result_flag result_47  = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::string>(Full_path_file_name_string_UTF8, char_p_for_write_47, ButeSize_for_write__47, PosEndOffsetFile_to_write_47);                //Вызываем.
	const ReadWrite_FromDisk_Cpp17__class::result_flag result_47 = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::wstring>(Full_path_file_name_wstring_UTF16, char_p_for_write_47, ButeSize_for_write__47, PosEndOffsetFile_to_write_47);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_47 = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::u16string>(Full_path_file_name_wstring_UTF16, char_p_for_write_47, ButeSize_for_write__47, PosEndOffsetFile_to_write_47);
	//const ReadWrite_FromDisk_Cpp17__class::result_flag result_47 = ReadWrite_FromDisk.write__to_SelectPos_File__OffsetEnd<std::u32string>(Full_path_file_name_wstring_UTF16, char_p_for_write_47, ButeSize_for_write__47, PosEndOffsetFile_to_write_47);
	
    //Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//---------------------------------------------------------------


   //---------------------------------------------------------------
	if (result_47 == ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		std::cout << "Result_47: OK" << std::endl;
	}
	else
	{
		std::cout << "Result_47:" << ReadWrite_FromDisk.get__NameError() << std::endl;

		return -1;
	}
	//---------------------------------------------------------------



	//-------------------------------------------------------------------------------------------30:write__to_SelectPos_File__OffsetEnd:Конец--------------------------------------------------------------------------------------------





	//----------------------------------------------------------------------------------------------------31:read__SplitLine_From_Begin:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - читает данные из файла строками через указанный разделитель строки. Чтение строк идет сначала файла.
	 //В качестве пути принимает кодировки: ASCII(std::string), UTF-16(std::u16string), UTF-16(wstring), UTF-32(std::u32string) и UTF-8(std::string) и соответвующий тип в качестве шаблона. 


	std::string split_48 = "W";           //Разделитель строк.

	//----------------------------------------------------------
	const std::string path_string_UTF8_48      = u8"D:\\Мусор\\";              //Путь до файла из которого нужно читать.
	const std::string File_Name_string_UTF8_48 = u8"Line.txt";                 //Имя файла из которого нужно читать.
	 
	const char*  pointer_to_Split_48           = split_48.c_str();             //Указатель на разделитель строк в файле.
	const size_t size_Split_48                 = split_48.size();              //Размер разделителя по указателю.

	const size_t number_read_Lines_48 = 3;                                      //Кол-во Line-срок, которые нужно прочитать из файла начиная с начала файла. Если нужно прочитать все строки из файла, ТО указать 0.

	std::vector<std::string>vec_splitLine_48;                                  //Сюда функция ДОБАВИТЬ в конец вектора, прочитанные строки.

	//Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//----------------------------------------------------------


	//-----------------------------------------------------------------------------------------------------
	//vec_splitLine_48.resize(0);     Так как функция добавляем результат в вектор, то если нужно чтобы результат был с начала вектора, то предварительно его обнуляем.
	

	const ReadWrite_FromDisk_Cpp17__class::result_flag result_48 = ReadWrite_FromDisk.read__SplitLine_From_Begin<std::string>(path_string_UTF8_48, File_Name_string_UTF8_48, pointer_to_Split_48, size_Split_48, vec_splitLine_48, number_read_Lines_48);


	if (result_48 != ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		if (result_48 == ReadWrite_FromDisk_Cpp17__class::result_flag::Line_NotFound)
		{
			std::cout << "Line_NotFound_48" << std::endl;
		}
		else
		{
			std::cout << "error_48:" << ReadWrite_FromDisk.get__NameError() << std::endl << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < vec_splitLine_48.size(); i++)
		{
			std::cout << vec_splitLine_48[i] << std::endl;
		}
	}
	//---------------------------------------------------------------------------------------------------



	//----------------------------------------------------------------------------------------------------31:read__SplitLine_From_Begin:Конец--------------------------------------------------------------------------------------------




	//----------------------------------------------------------------------------------------------------32:read__SplitLine_From_Begin:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - читает данные из файла строками через указанный разделитель строки. Чтение строк идет сначала файла.
	 //В качестве пути принимает кодировки: ASCII(std::string), UTF-16(std::u16string), UTF-16(wstring), UTF-32(std::u32string) и UTF-8(std::string) и соответвующий тип в качестве шаблона. 


	std::string split_49 = "W";           //Разделитель строк.

	//----------------------------------------------------------
	const std::string Full_path_file_name_wstring_UTF8_49 = u8"D:\\Мусор\\Line.txt";              //Полный Путь до файла из которого нужно читать.

	const char* pointer_to_Split_49 = split_49.c_str();                                         //Указатель на разделитель строк в файле.
	const size_t size_Split_49 = split_49.size();                                               //Размер разделителя по указателю.

	const size_t number_read_Lines_49 = 3;                                        //Кол-во Line-срок, которые нужно прочитать из файла начиная с начала файла. Если нужно прочитать все строки из файла, ТО указать 0.

	std::vector<std::string>vec_splitLine_49;                                  //Сюда функция ДОБАВИТЬ в конец вектора, прочитанные строки.

	//Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//----------------------------------------------------------


	//-----------------------------------------------------------------------------------------------------
	//vec_splitLine_49.resize(0);     Так как функция добавляем результат в вектор, то если нужно чтобы результат был с начала вектора, то предварительно его обнуляем.


	const ReadWrite_FromDisk_Cpp17__class::result_flag result_49 = ReadWrite_FromDisk.read__SplitLine_From_Begin<std::string>(Full_path_file_name_wstring_UTF8_49, pointer_to_Split_49, size_Split_49, vec_splitLine_49, number_read_Lines_49);


	if (result_49 != ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		if (result_49 == ReadWrite_FromDisk_Cpp17__class::result_flag::Line_NotFound)
		{
			std::cout << "Line_NotFound_49" << std::endl;
		}
		else
		{
			std::cout << "error_49:" << ReadWrite_FromDisk.get__NameError() << std::endl << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < vec_splitLine_49.size(); i++)
		{
			std::cout << vec_splitLine_49[i] << std::endl;
		}
	}
	//---------------------------------------------------------------------------------------------------



	//----------------------------------------------------------------------------------------------------32:read__SplitLine_From_Begin:Конец--------------------------------------------------------------------------------------------







	//----------------------------------------------------------------------------------------------------33:read__SplitLine_From_End:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - читает данные из файла строками через указанный разделитель строки. Чтение строк идет с конца файла.
	 //В качестве пути принимает кодировки: ASCII(std::string), UTF-16(std::u16string), UTF-16(wstring), UTF-32(std::u32string) и UTF-8(std::string) и соответвующий тип в качестве шаблона. 


	std::string split_50 = "W";           //Разделитель строк.

	//----------------------------------------------------------
	const std::string path_string_UTF8_50            = u8"D:\\Мусор\\";              //Путь до файла из которого нужно читать.
	const std::string File_Name_string_UTF8_50       = u8"Line.txt";                 //Имя файла из которого нужно читать.

	const char* pointer_to_Split_50                  = split_50.c_str();             //Указатель на разделитель строк в файле.
	const size_t size_Split_50                       = split_50.size();              //Размер разделителя по указателю.

	const size_t number_read_Lines_50                = 3;                                      //Кол-во Line-срок, которые нужно прочитать из файла начиная с начала файла. Если нужно прочитать все строки из файла, ТО указать 0.

	std::vector<std::string>vec_splitLine_50;                                  //Сюда функция ДОБАВИТЬ в конец вектора, прочитанные строки.

	//Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//----------------------------------------------------------


	//-----------------------------------------------------------------------------------------------------
	//vec_splitLine_50.resize(0);     Так как функция добавляем результат в вектор, то если нужно чтобы результат был с начала вектора, то предварительно его обнуляем.


	const ReadWrite_FromDisk_Cpp17__class::result_flag result_50 = ReadWrite_FromDisk.read__SplitLine_From_End<std::string>(path_string_UTF8_50, File_Name_string_UTF8_50, pointer_to_Split_50, size_Split_50, vec_splitLine_50, number_read_Lines_50);


	if (result_50 != ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		if (result_50 == ReadWrite_FromDisk_Cpp17__class::result_flag::Line_NotFound)
		{
			std::cout << "Line_NotFound_50" << std::endl;
		}
		else
		{
			std::cout << "error_50:" << ReadWrite_FromDisk.get__NameError() << std::endl << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < vec_splitLine_50.size(); i++)
		{
			std::cout << vec_splitLine_50[i] << std::endl;
		}
	}
	//---------------------------------------------------------------------------------------------------



	//----------------------------------------------------------------------------------------------------33:read__SplitLine_From_End:Конец--------------------------------------------------------------------------------------------







	//----------------------------------------------------------------------------------------------------34:read__SplitLine_From_End:Начало--------------------------------------------------------------------------------------------

	 //Это шаблонная функция - читает данные из файла строками через указанный разделитель строки. Чтение строк идет сначала файла.
	 //В качестве пути принимает кодировки: ASCII(std::string), UTF-16(std::u16string), UTF-16(wstring), UTF-32(std::u32string) и UTF-8(std::string) и соответвующий тип в качестве шаблона. 


	std::string split_51 = "W";           //Разделитель строк.

	//----------------------------------------------------------
	const std::string Full_path_file_name_wstring_UTF8_51 = u8"D:\\Мусор\\Line.txt";              //Полный Путь до файла из которого нужно читать.

	const char* pointer_to_Split_51 = split_51.c_str();                                         //Указатель на разделитель строк в файле.
	const size_t size_Split_51 = split_51.size();                                               //Размер разделителя по указателю.

	const size_t number_read_Lines_51 = 3;                                        //Кол-во Line-срок, которые нужно прочитать из файла начиная с начала файла. Если нужно прочитать все строки из файла, ТО указать 0.

	std::vector<std::string>vec_splitLine_51;                                  //Сюда функция ДОБАВИТЬ в конец вектора, прочитанные строки.

	//Поток до файла закрывается только в случае ошибки, при успешном завершении поток не закрывается. Когда закончена работа с файлом - нужно закрыть его через "stream_close()".
	//----------------------------------------------------------


	//-----------------------------------------------------------------------------------------------------
	//vec_splitLine_51.resize(0);     Так как функция добавляем результат в вектор, то если нужно чтобы результат был с начала вектора, то предварительно его обнуляем.


	const ReadWrite_FromDisk_Cpp17__class::result_flag result_51 = ReadWrite_FromDisk.read__SplitLine_From_End<std::string>(Full_path_file_name_wstring_UTF8_51, pointer_to_Split_51, size_Split_51, vec_splitLine_51, number_read_Lines_51);


	if (result_51 != ReadWrite_FromDisk_Cpp17__class::result_flag::OK)
	{
		if (result_51 == ReadWrite_FromDisk_Cpp17__class::result_flag::Line_NotFound)
		{
			std::cout << "Line_NotFound_51" << std::endl;
		}
		else
		{
			std::cout << "error_51:" << ReadWrite_FromDisk.get__NameError() << std::endl << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < vec_splitLine_51.size(); i++)
		{
			std::cout << vec_splitLine_51[i] << std::endl;
		}
	}
	//---------------------------------------------------------------------------------------------------



	//----------------------------------------------------------------------------------------------------34:read__SplitLine_From_End:Конец--------------------------------------------------------------------------------------------



)
