

    //Это просто простой класс обертка над std::fstream - для Записи и Чтения в/из файла в бинарном режиме.


   //Доступные методы: примеры смотреть в main.cpp
   
   //Создание пустого файла
   //Получить размер файла в байтах
   //ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В КОНЕЦ STD::STRING
   //ЧТЕНИЕ ЗАДАННОЙ ПРОИЗВОЛЬНОЙ ЧАСТИ ФАЙЛА В КОНЕЦ STD::STRING
   //ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(со смещением от начала и указанием смещения от конца) В КОНЕЦ STD::STRING
   //ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения только от конца) В КОНЕЦ STD::STRING
   //ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ
   //ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ
   //ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ
   //ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ
   //ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ ВЫДЕЛЕННУЮ ПАМЯТЬ
   //ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ВЫДЕЛЕННУЮ ПАМЯТЬ
   //ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ
   //ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ
   //ЗАПИСЬ В ФАЙЛ С ПРЕДВАРИТЕЛЬНЫМ ЕГО ОБНУЛЕНИЕМ
   //ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА БЕЗ ОБНУЛЕНИЯ
   //ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА(с указанием смещения от конца) БЕЗ ОБНУЛЕНИЯ
   //stream_close() - принудительно закрывает поток до файла, если необходимо.
   //ЧТЕНИЕ ИЗ ФАЙЛА В Line-СТРОКИ ЧЕРЕЗ РАЗДЕЛИТЕЛЬ(С НАЧАЛА ФАЙЛА)
   //ЧТЕНИЕ ИЗ ФАЙЛА В Line-СТРОКИ ЧЕРЕЗ РАЗДЕЛИТЕЛЬ(С КОНЦА ФАЙЛА)



	//***********************Создание пустого файла:начало*******************
	//Данные шаблонные мметоды просто создают пустой файл.
	
	// template<typename T> const result_flag create__EmptyFile(const T& path_name, const T& file_name)
	// template<typename T> const result_flag create__EmptyFile(const T& FullPath_name)
	//***********************Создание пустого файла:начало*******************


	//***********************Получить размер файла в байтах:начало*******************
	//Данные шаблонные мметоды возвращают размер файла в байтах. 
	
	// template<typename T> const result_flag get__FilebyteSize(const T& path_name, const T& file_name, size_t& File_size);              
	// template<typename T> const result_flag get__FilebyteSize(const T& FullPath_name, size_t& File_size)
	//***********************Получить размер файла в байтах:начало*******************


	//***********************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В КОНЕЦ STD::STRING:начало*******************		
	//Данные шаблонные мметоды считывают все содержимое файла в конец "string_for_read", размер "string_for_read" устанвливается внутри функции - то есть увеличивается на размер добавленных считанных данных из файла Смотреть примеры вызова ниже.
	
	//1: template<typename T> const result_flag read__FullFile_to_StringBack(const T& path_name, const T& file_name, std::string& string_for_read)
	
	//2: template<typename T> const result_flag read__FullFile_to_StringBack(const T& FullPath_name, std::string& string_for_read)	
	//***********************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В КОНЕЦ STD::STRING:начало*******************

 
	//***********************ЧТЕНИЕ ЗАДАННОЙ ПРОИЗВОЛЬНОЙ ЧАСТИ ФАЙЛА В КОНЕЦ STD::STRING:начало*******************
	//Данные шаблонные мметоды считывают Указанную Пользователем часть содержимое файла в конец "string_for_read", размер "string_for_read" устанвливается внутри функции под размер указанной части. Смотреть примеры вызова ниже.
	
	//3: template<typename T> const result_flag read__PartFile_to_StringBack(const T& path_name, const T& file_name, std::string& string_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)

	//4: template<typename T> const result_flag read__PartFile_to_StringBack(const T& FullPath_name, std::string& string_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ПРОИЗВОЛЬНОЙ ЧАСТИ ФАЙЛА В КОНЕЦ STD::STRING:начало*******************


	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(со смещением от начала и указанием смещения от конца) В КОНЕЦ STD::STRING:начало*******************
	//Данные шаблонные мметоды считывают Указанную Пользователем часть содержимое файла в конец "string_for_read", размер "string_for_read" устанвливается внутри функции под размер указанной части. Смотреть примеры вызова ниже.
	
	//5:  template<typename T> const result_flag read__PartFile_to_StringBack__OffsetEnd(const T& path_name, const T& file_name, std::string& string_for_read, const size_t PosInFile_beg, const flags end_flag, const size_t offset_from_end)

	//6: template<typename T> const result_flag read__PartFile_to_StringBack__OffsetEnd(const T& FullPath_name, std::string& string_for_read, const size_t PosInFile_beg, const flags end_flag, const size_t offset_from_end)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(со смещением от начала и указанием смещения от конца) В КОНЕЦ STD::STRING:начало*******************


	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения только от конца) В КОНЕЦ STD::STRING:начало*******************
	//7:  template<typename T> const result_flag read__PartFile_to_StringBack__DoubleOffsetEnd(const T& path_name, const T& file_name, std::string& string_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end)

	//8: template<typename T> const result_flag read__PartFile_to_StringBack__DoubleOffsetEnd(const T& FullPath_name, std::string& string_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с  двойным указанием смещения только от конца) В КОНЕЦ STD::STRING:начало*******************


	//***********************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*******************
	//Данные шаблонные мметоды считывают все содержимое файла в предоставленный указатель. Внутри функция ни как не меняет размер памяти по предсотавленном указателю, поэтому необходимо следить, что место в указателе было достаточно для записи данных, в ином случае - попытка записи данных из файла большего размера, чем выделенная по предоставленному указателю память - приведет в итоге к ошибке. Смотреть примеры вызова ниже.

	//9: template<typename T> const result_flag read__FullFile_to_FixSizeCharPointer(const T& path_name, const T& file_name, char* char_for_read)

	//10: template<typename T> const result_flag read__FullFile_to_FixSizeCharPointer(const T& FullPath_name, char* char_for_read)
	//***********************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*******************



	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*******************
	//Данные шаблонные мметоды считывают Указанную Пользователем часть содержимое файла в предоставленный указатель. Внутри функция ни как не меняет размер памяти по предсотавленном указателю, поэтому необходимо следить, что место в указателе было достаточно для записи данных, в ином случае - попытка записи данных из файла большего размера, чем выделенная по предоставленному указателю память - приведет в итоге к ошибке. Смотреть примеры вызова ниже.
	
	//11: template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer(const T& path_name, const T& file_name, char* char_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)

	//12: template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer(const T& FullPath_name, char* char_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*******************



	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*******************
	//Данные шаблонные мметоды считывают Указанную Пользователем часть содержимое файла в предоставленный указатель. Внутри функция ни как не меняет размер памяти по предсотавленном указателю, поэтому необходимо следить, что место в указателе было достаточно для записи данных, в ином случае - попытка записи данных из файла большего размера, чем выделенная по предоставленному указателю память - приведет в итоге к ошибке. Смотреть примеры вызова ниже.
	
	//13: template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer__OffsetEnd(const T& path_name, const T& file_name, char* char_for_read, const size_t PosInFile_beg, const flags end_flag, const size_t offset_from_end)

	//14: template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer__OffsetEnd(const T& FullPath_name, char* char_for_read, const size_t PosInFile_beg, const flags end_flag, const size_t offset_from_end)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*******************



    //***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*******************
	//15: template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd(const T& path_name, const T& file_name, char* char_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)

	//16: template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd(const T& FullPath_name, char* char_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*******************


	//***********************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*******************
	//Данные шаблонные мметоды считывают все содержимое файла в предоставленный адресс на сырой указатель, функция внутри выделяет память под указатель в размере содержмого файла и в конце устанавивает заверщающий ноль, размер прочитанных данных записывается в переданный "read_size". Смотреть примеры вызова ниже.

	//17: template<typename T> const result_flag read__FullFile_to_DynamicRawPointer(const T& path_name, const T& file_name, char** char_p_p, size_t& read_size)

	//18: template<typename T> const result_flag read__FullFile_to_DynamicRawPointer(const T& FullPath_name, char** char_p_p, size_t& read_size)
	//***********************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*******************



	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*******************
	//Данные шаблонные мметоды считывают Указанную Пользователем часть содержимое файла в предоставленный адресс на сырой указатель, функция внутри выделяет память под указатель в размере содержмого файла и в конце устанавивает заверщающий ноль. Смотреть примеры вызова ниже.

	//19: template<typename T> const result_flag read__PartFile_to_DynamicRawPointer(const T& path_name, const T& file_name, char** char_p_p, const size_t PosInFile_beg, const size_t PosInFile_end)

	//20: template<typename T> const result_flag read__PartFile_to_DynamicRawPointer(const T& FullPath_name, char** char_p_p, const size_t PosInFile_beg, const size_t PosInFile_end)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*******************


 
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*******************
	//Данные шаблонные мметоды считывают Указанную Пользователем часть содержимое файла в предоставленный адресс на сырой указатель, функция внутри выделяет память под указатель в размере содержмого файла и в конце устанавивает заверщающий ноль, размер прочитанных данных записывается в переданный "read_size". Смотреть примеры вызова ниже.
	
	//21: template<typename T> const result_flag read__PartFile_to_DynamicRawPointer__OffsetEnd(const T& path_name, const T& file_name, char** char_p_p, const size_t PosInFile_beg, const flags end_flag, const size_t offset_from_end, size_t& read_size)

	//22: template<typename T> const result_flag read__PartFile_to_DynamicRawPointer__OffsetEnd(const T& FullPath_name, char** char_p_p, const size_t PosInFile_beg, const flags end_flag, const size_t offset_from_end, size_t& read_size)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*******************



	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*******************
	//23: template<typename T> const result_flag read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd(const T& path_name, const T& file_name, char** char_p_p, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)

	//24:template<typename T> const result_flag read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd(const T& FullPath_name, char** char_p_p, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)
	//***********************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*******************



	//******************ЗАПИСЬ В ФАЙЛ С ПРЕДВАРИТЕЛЬНЫМ ЕГО ОБНУЛЕНИЕМ:начало***********************************
	//Данные шаблонные мметоды записывают данные в файл из переданного указателя в указанном "ByteSize_for_write" размере. Файл для записи открывается с предварительный удаленеим все данных из него. Смотреть примеры вызова ниже.
	
	//25: template<typename T> const result_flag write__to_PreClear_File(const T& path_name, const T& file_name, const char* char_p, const size_t ByteSize_for_write)

	//26: template<typename T> const result_flag write__to_PreClear_File(const T& FullPath_name, const char* char_p, const size_t ByteSize_for_write)
	//***********************ЗАПИСЬ В ФАЙЛ С ПРЕДВАРИТЕЛЬНЫМ ЕГО ОБНУЛЕНИЕМ:начало***********************************



	//******************ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА БЕЗ ОБНУЛЕНИЯ:начало***********************************
	//Данные шаблонные мметоды записывают данные в файл из переданного указателя в указанном "ByteSize_for_write" размере с указанием позиции в файле с которого необходимо произвести запись. Данные файла при открытии файла за для записи - не обнуляются.

	//27: template<typename T> const result_flag write__to_SelectPos_File(const T& path_name, const T& file_name, const char* char_p, const size_t ByteSize_for_write, const size_t Pos_in_File)

	//28: template<typename T> const result_flag write__to_SelectPos_File(const T& FullPath_name, const char* char_p, const size_t ByteSize_for_write, const size_t Pos_in_File)
	//***********************ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА БЕЗ ОБНУЛЕНИЯ:начало***********************************
	
	
	//****************ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА(с указанием смещения от конца) БЕЗ ОБНУЛЕНИЯ:начало***********************************
	//Данные шаблонные мметоды записывают данные в файл из переданного указателя в указанном "ByteSize_for_write" размере с указанием позиции в файле с которого необходимо произвести запись. Данные файла при открытии файла за для записи - не обнуляются.
	
	//29: template<typename T> const result_flag write__to_SelectPos_File__OffsetEnd(const T& path_name, const T& file_name, const char* char_p, const flags end_flag, const size_t offset_from_end)

    //30: template<typename T> const result_flag write__to_SelectPos_File__OffsetEnd(const T& FullPath_name, const char* char_p, const flags end_flag, const size_t offset_from_end)
	//*********************ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА(с указанием смещения от конца) БЕЗ ОБНУЛЕНИЯ:начало***********************************



    //*****************************************************************
	// void stream_close()                    - принудительно закрывает поток до файла, если необходимо.

	// const std::string& get__NameError()    - возвращает строку с общим описанием ошибки в случае, если функция возвращает результат отличный от "ReadWrite_FromDisk_Cpp17__class::result_flag::OK".
	//*****************************************************************



	//****************ЧТЕНИЕ ИЗ ФАЙЛА В Line-СТРОКИ ЧЕРЕЗ РАЗДЕЛИТЕЛЬ(С НАЧАЛА ФАЙЛА):начало***********************************
    //31: template<typename T> const result_flag read__SplitLine_From_Begin(const T& path_name, const T& file_name, const char* poiter_to_SplitSubstr, const size_t size_SplitSubstr, std::vector<std::string>& vec__SplitLine_result, const size_t number_Line)
    
	//32: template<typename T> const result_flag read__SplitLine_From_Begin(const T& FullPath_name, const char* poiter_to_SplitSubstr, const size_t size_SplitSubstr, std::vector<std::string>& vec__SplitLine_result, const size_t number_Line)
	//****************ЧТЕНИЕ ИЗ ФАЙЛА В Line-СТРОКИ ЧЕРЕЗ РАЗДЕЛИТЕЛЬ(С НАЧАЛА ФАЙЛА):начало***********************************



	//****************ЧТЕНИЕ ИЗ ФАЙЛА В Line-СТРОКИ ЧЕРЕЗ РАЗДЕЛИТЕЛЬ(С КОНЦА ФАЙЛА):начало***********************************
    //33: template<typename T> const result_flag read__SplitLine_From_End(const T& path_name, const T& file_name, const char* poiter_to_SplitSubstr, const size_t size_SplitSubstr, std::vector<std::string>& vec__SplitLine_result, const size_t number_Line)

	//34: template<typename T> const result_flag read__SplitLine_From_End(const T& FullPath_name, const char* poiter_to_SplitSubstr, const size_t size_SplitSubstr, std::vector<std::string>& vec__SplitLine_result, const size_t number_Line)
	//****************ЧТЕНИЕ ИЗ ФАЙЛА В Line-СТРОКИ ЧЕРЕЗ РАЗДЕЛИТЕЛЬ(С КОНЦА ФАЙЛА):начало***********************************




