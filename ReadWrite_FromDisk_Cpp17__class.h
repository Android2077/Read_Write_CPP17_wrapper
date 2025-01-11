#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>






class ReadWrite_FromDisk_Cpp17__class
{

public:
	
	enum class result_flag : int
	{
		OK = 0,
		std__FileSystem_error = 1,
		bad_alloc_error = 2,
		fstream_error = 3,
		File_Exixst = 4,
		File_NotExixst = 5,
		File_empty = 6,
		Line_NotFound = 7,
	};


	~ReadWrite_FromDisk_Cpp17__class()
	{
		stream_close();
	}


public:


	void stream_close()
	{
		if (fstream_.is_open() == true)
		{
			//Значит поток на данный момент открыт, закроем его.

			fstream_.close();
		}
	}

	const std::string& get__NameError()
	{
		return ErrorName;
	}




	//********************************************************************************************Проверка наличие сущестовования файла:начало*********************************************************************************
	template<typename T> const result_flag check__FileExist(const T& path_name, const T& file_name)
	{
		try { FS_path = path_name + file_name; } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		//-----------------------------------------------------
		const bool res = std::filesystem::exists(FS_path);

		if (res == true)
		{
			if (file_name == L"")
			{
				return result_flag::File_NotExixst;
			}
			else
			{
				return result_flag::File_Exixst;
			}
		}
		else
		{
			return result_flag::File_NotExixst;
		}
		//-----------------------------------------------------
	}
	template<typename T> const result_flag check__FileExist(const T& FullPath_name)
	{
		try { FS_path = FullPath_name; } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		//-----------------------------------------------------
		const bool res = std::filesystem::exists(FS_path);

		if (res == true)
		{
			return result_flag::File_Exixst;
		}
		else
		{
			return result_flag::File_NotExixst;
		}
		//-----------------------------------------------------

	}
	//********************************************************************************************Проверка наличие сущестовования файла:конец*********************************************************************************




	//********************************************************************************************Создание пустого файла:начало*********************************************************************************
	template<typename T> const result_flag create__EmptyFile(const T& path_name, const T& file_name)
	{
		return Run_create__EmptyFile<T>(path_name, file_name);
	}
	template<typename T> const result_flag create__EmptyFile(const T& FullPath_name)
	{
		return Run_create__EmptyFile<T>(FullPath_name);
	}
	//********************************************************************************************Создание пустого файла:конец*********************************************************************************



	//********************************************************************************************Получить размер файла в байтах:начало*********************************************************************************
	template<typename T> const result_flag get__FilebyteSize(const T& path_name, const T& file_name, size_t& File_size)
	{
		return Run_get__FilebyteSize<T>(path_name, file_name, File_size);
	}
	template<typename T> const result_flag get__FilebyteSize(const T& FullPath_name, size_t& File_size)
	{
		return Run_get__FilebyteSize<T>(FullPath_name, File_size);
	}
	//********************************************************************************************Получить размер файла в байтах:конец*********************************************************************************






	//********************************************************************************************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В КОНЕЦ STD::STRING:начало*********************************************************************************		
	template<typename T> const result_flag read__FullFile_to_StringBack(const T& path_name, const T& file_name, std::string& string_for_read)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_FullFile_to_StringBack(string_for_read);     //Читаем файл целиком в конец "string_for_read".
	}
	
	template<typename T> const result_flag read__FullFile_to_StringBack(const T& FullPath_name, std::string& string_for_read)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }     //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_FullFile_to_StringBack(string_for_read);     //Читаем файл целиком в конец "string_for_read".
	}	
	//********************************************************************************************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В КОНЕЦ STD::STRING:конец*********************************************************************************
	
	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В КОНЕЦ STD::STRING:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_StringBack(const T& path_name, const T& file_name, std::string& string_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_StringBack(string_for_read, PosInFile_beg, PosInFile_end);     //Читаем файл целиком в конец "string_for_read".
	}
	
	template<typename T> const result_flag read__PartFile_to_StringBack(const T& FullPath_name, std::string& string_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_StringBack(string_for_read, PosInFile_beg, PosInFile_end);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В КОНЕЦ STD::STRING:конец*********************************************************************************

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В КОНЕЦ STD::STRING:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_StringBack__OffsetEnd(const T& path_name, const T& file_name, std::string& string_for_read, const size_t PosInFile_beg, const size_t offset_from_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_StringBack__OffsetEnd(string_for_read, PosInFile_beg, offset_from_end);     //Читаем файл целиком в конец "string_for_read".
	}
	
	template<typename T> const result_flag read__PartFile_to_StringBack__OffsetEnd(const T& FullPath_name, std::string& string_for_read, const size_t PosInFile_beg, const size_t offset_from_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_StringBack__OffsetEnd(string_for_read, PosInFile_beg, offset_from_end);     //Читаем файл целиком в конец "string_for_read".
	}

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В КОНЕЦ STD::STRING:конец*********************************************************************************

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В КОНЕЦ STD::STRING:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_StringBack__DoubleOffsetEnd(const T& path_name, const T& file_name, std::string& string_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_StringBack__DoubleOffsetEnd(string_for_read, Beg_offset_from_end, End_offset_from_end);     //Читаем файл целиком в конец "string_for_read".
	}

	template<typename T> const result_flag read__PartFile_to_StringBack__DoubleOffsetEnd(const T& FullPath_name, std::string& string_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_StringBack__DoubleOffsetEnd(string_for_read, Beg_offset_from_end, End_offset_from_end);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с  двойным указанием смещения от конца) В КОНЕЦ STD::STRING:конец*********************************************************************************



	//********************************************************************************************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:начало*********************************************************************************
	template<typename T> const result_flag read__FullFile_to_FixSizeCharPointer(const T& path_name, const T& file_name, char* char_for_read)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_FullFile_to_FixSizeCharPointer(char_for_read);     //Читаем файл целиком в конец "string_for_read".
	}

	template<typename T> const result_flag read__FullFile_to_FixSizeCharPointer(const T& FullPath_name, char* char_for_read)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_FullFile_to_FixSizeCharPointer(char_for_read);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:конец*********************************************************************************

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer(const T& path_name, const T& file_name, char* char_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_FixSizeCharPointer(char_for_read, PosInFile_beg, PosInFile_end);     //Читаем файл целиком в конец "string_for_read".
	}
	
	template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer(const T& FullPath_name, char* char_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_FixSizeCharPointer(char_for_read, PosInFile_beg, PosInFile_end);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:конец*********************************************************************************

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer__OffsetEnd(const T& path_name, const T& file_name, char* char_for_read, const size_t PosInFile_beg, const size_t offset_from_end, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_FixSizeCharPointer__OffsetEnd(char_for_read, PosInFile_beg, offset_from_end, read_size);     //Читаем файл целиком в конец "string_for_read".
	}
	
	template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer__OffsetEnd(const T& FullPath_name, char* char_for_read, const size_t PosInFile_beg, const size_t offset_from_end, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_FixSizeCharPointer__OffsetEnd(char_for_read, PosInFile_beg, offset_from_end, read_size);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:конец*********************************************************************************

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd(const T& path_name, const T& file_name, char* char_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_FixSizeCharPointer__DoubleOffsetEnd(char_for_read, Beg_offset_from_end, End_offset_from_end, read_size);     //Читаем файл целиком в конец "string_for_read".
	}

	template<typename T> const result_flag read__PartFile_to_FixSizeCharPointer__DoubleOffsetEnd(const T& FullPath_name, char* char_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_FixSizeCharPointer__DoubleOffsetEnd(char_for_read, Beg_offset_from_end, End_offset_from_end, read_size);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ПЕРЕДАННЫЙ УКАЗАТЕЛЬ:конец*********************************************************************************



	
	//********************************************************************************************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ ВЫДЕЛЕННУЮ ПАМЯТЬ:начало*********************************************************************************
	template<typename T> const result_flag read__FullFile_to_DynamicRawPointer(const T& path_name, const T& file_name, char** char_p_p, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_FullFile_to_DynamicRawPointer(char_p_p, read_size);     //Читаем файл целиком в конец "string_for_read".
	}

	template<typename T> const result_flag read__FullFile_to_DynamicRawPointer(const T& FullPath_name, char** char_p_p, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_FullFile_to_DynamicRawPointer(char_p_p, read_size);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕ ФАЙЛА ЦЕЛИКОМ В ВЫДЕЛЕННУЮ ПАМЯТЬ:конец*********************************************************************************

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА В ВЫДЕЛЕННУЮ ПАМЯТЬ:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_DynamicRawPointer(const T& path_name, const T& file_name, char** char_p_p, const size_t PosInFile_beg, const size_t PosInFile_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_DynamicRawPointer(char_p_p, PosInFile_beg, PosInFile_end);     //Читаем файл целиком в конец "string_for_read".
	}

	template<typename T> const result_flag read__PartFile_to_DynamicRawPointer(const T& FullPath_name, char** char_p_p, const size_t PosInFile_beg, const size_t PosInFile_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_DynamicRawPointer(char_p_p, PosInFile_beg, PosInFile_end);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕЗАДАННОЙ ЧАСТИ ФАЙЛА В ВЫДЕЛЕННУЮ ПАМЯТЬ:конец*********************************************************************************

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_DynamicRawPointer__OffsetEnd(const T& path_name, const T& file_name, char** char_p_p, const size_t PosInFile_beg, const size_t offset_from_end, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_DynamicRawPointer__OffsetEnd(char_p_p, PosInFile_beg, offset_from_end, read_size);     //Читаем файл целиком в конец "string_for_read".
	}

	template<typename T> const result_flag read__PartFile_to_DynamicRawPointer__OffsetEnd(const T& FullPath_name, char** char_p_p, const size_t PosInFile_beg, const size_t offset_from_end, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_DynamicRawPointer__OffsetEnd(char_p_p, PosInFile_beg, offset_from_end, read_size);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕЗАДАННОЙ ЧАСТИ ФАЙЛА(с указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ:конец*********************************************************************************

	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ:НАЧАЛО*********************************************************************************
	template<typename T> const result_flag read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd(const T& path_name, const T& file_name, char** char_p_p, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_DynamicRawPointer__DoubleOffsetEnd(char_p_p, Beg_offset_from_end, End_offset_from_end, read_size);     //Читаем файл целиком в конец "string_for_read".
	}

	template<typename T> const result_flag read__PartFile_to_DynamicRawPointer__DoubleOffsetEnd(const T& FullPath_name, char** char_p_p, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Read_PartFile_to_DynamicRawPointer__DoubleOffsetEnd(char_p_p, Beg_offset_from_end, End_offset_from_end, read_size);     //Читаем файл целиком в конец "string_for_read".
	}
	//********************************************************************************************ЧТЕНИЕ ЗАДАННОЙ ЧАСТИ ФАЙЛА(с двойным указанием смещения от конца) В ВЫДЕЛЕННУЮ ПАМЯТЬ:конец*********************************************************************************




	
	

	//***************************************************************************************ЗАПИСЬ В ФАЙЛ С ПРЕДВАРИТЕЛЬНЫМ ЕГО ОБНУЛЕНИЕМ:начало*************************************************************************************************
	template<typename T> const result_flag write__to_PreClear_File(const T& path_name, const T& file_name, const char* char_p, const size_t ByteSize_for_write)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, true); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Write_to_PreClearFile(char_p, ByteSize_for_write);     
	}

	template<typename T> const result_flag write__to_PreClear_File(const T& FullPath_name, const char* char_p, const size_t ByteSize_for_write)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, true); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Write_to_PreClearFile(char_p, ByteSize_for_write);     
	}
	//********************************************************************************************ЗАПИСЬ В ФАЙЛ С ПРЕДВАРИТЕЛЬНЫМ ЕГО ОБНУЛЕНИЕМ:конец*************************************************************************************************

	//***************************************************************************************ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА БЕЗ ОБНУЛЕНИЯ:начало*************************************************************************************************
	template<typename T> const result_flag write__to_SelectPos_File(const T& path_name, const T& file_name, const char* char_p, const size_t ByteSize_for_write, const size_t Pos_in_File)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Write__to_SelectPos_File(char_p, ByteSize_for_write, Pos_in_File);     
	}

	template<typename T> const result_flag write__to_SelectPos_File(const T& FullPath_name, const char* char_p, const size_t ByteSize_for_write, const size_t Pos_in_File)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Write__to_SelectPos_File(char_p, ByteSize_for_write, Pos_in_File);    
	}
	//********************************************************************************************ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА БЕЗ ОБНУЛЕНИЯ:конец*************************************************************************************************
	
	
	//*************************************************************************************ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА(с указанием смещения от конца) БЕЗ ОБНУЛЕНИЯ:начало*************************************************************************************************
	template<typename T> const result_flag write__to_SelectPos_File__OffsetEnd(const T& path_name, const T& file_name, const char* char_p, const size_t ByteSize_for_write, const size_t offset_from_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(path_name, file_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Write__to_SelectPos_File__OffsetEnd(char_p, ByteSize_for_write, offset_from_end);
	}

	template<typename T> const result_flag write__to_SelectPos_File__OffsetEnd(const T& FullPath_name, const char* char_p, const size_t ByteSize_for_write, const size_t offset_from_end)
	{
		const result_flag res = Check_for_SetNewPath_and_CheckStreamClose(FullPath_name, false); if (res != result_flag::OK) { return res; }   //Устанавливаем новый переданный путь и Проверям на необходимость закрытия потока к предыдущему файлу.

		return Run_Write__to_SelectPos_File__OffsetEnd(char_p, ByteSize_for_write, offset_from_end);
	}
	//******************************************************************************************ЗАПИСЬ В ФАЙЛ С КОНКРЕТНОГО МЕСТА(с указанием смещения от конца) БЕЗ ОБНУЛЕНИЯ:конец*************************************************************************************************
	



	//**************************************************************************************ЧТЕНИЕ ИЗ ФАЙЛА SPLIT-LINE`ом:Начало***********************************************************************
	template<typename T> const result_flag read__SplitLine_From_Begin(const T& path_name, const T& file_name, const char* poiter_to_SplitSubstr, const size_t size_SplitSubstr, std::vector<std::string>& vec__SplitLine_result, const size_t number_Line)
	{

		Check_for_SetNewPath_and_CheckStreamClose<T>(path_name, file_name, false);


		//-------------------------------------------------
		result_flag res = open_stream();

		if (res != result_flag::OK)
		{
			return res;
		}
		//-------------------------------------------------




		//----------------------Определим размер файла:---------------------------
		fstream_.seekg(0, std::ios::end);   //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		size_t File_size = fstream_.tellg();    //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.
		
		if (File_size == 0)
		{
			ErrorName = "read__SplitLine_From_Begin:File_empty";
			return result_flag::File_empty;
		}

		File_size = File_size - 1;
		//------------------------------------------------------------------------




		//------------------------------------------
		if (size_SplitSubstr > (File_size+1))
		{
			return result_flag::Line_NotFound;
		}
		//------------------------------------------


		const size_t save_size = vec__SplitLine_result.size();



		//***************************************************************************************************************************************************************

		//--------------------------------------------------
		std::string chunk_string;

		size_t chunk_diapazon_start = 0;
		size_t chunk_diapazon_end = size_SplitSubstr - 1;

		long long Line_diapazon_start = 0;
		long long Line_diapazon_end   = 0;

		size_t add_Line_cntr = 0;
		//--------------------------------------------------

		for (;;)
		{
			//-----------------------------------------------------------------------------------------------
			chunk_string.resize(0);

			res = Run_Read_PartFile_to_StringBack__(chunk_string, chunk_diapazon_start, chunk_diapazon_end);

			if (res != result_flag::OK)
			{
				return res;
			}
			else
			{

				if (chunk_string.compare(poiter_to_SplitSubstr) == 0)
				{
					//Значит прочитанный диапазон из файла - это разделитель:

					const size_t pos_delimeter = chunk_diapazon_start;   //Позиция в файле найденного разделителя.

					Line_diapazon_end = pos_delimeter - 1;


					if (Line_diapazon_end >= Line_diapazon_start)
					{
						//Значит есть данные для копирования их как Line-строки:

						//------------------------------------------------------------------------------
						//Прочитаем этот диапазон из файла:
						
						if (number_Line == 0 || number_Line > add_Line_cntr)
						{
							vec__SplitLine_result.emplace_back();

							res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_start, Line_diapazon_end);

							if (res != result_flag::OK)
							{
								return res;
							}
						}
						else
						{
							return result_flag::OK;
						}

						add_Line_cntr++;
						//------------------------------------------------------------------------------


						Line_diapazon_start = pos_delimeter + size_SplitSubstr;    //Устанавливаем новую стартовую позицию для чтения следующей Line-строки из файла.


						if (Line_diapazon_start > File_size)
						{
							//Значит вышли за пределы файла и все Line-строки уже сохранены.

							return result_flag::OK;
						}
						else
						{
							//Значит еще есть байты до конца файла:

							const long long tail_size = File_size - Line_diapazon_start + 1;     //Сколько байт осталось от байта следующего сразу за разделителем до конца файла.

							if (tail_size > size_SplitSubstr)
							{
								//Значит до конца файла - еще умещается, как сам разделитель так и полезные байты между ним. Поэтому просто повторяем стандартный цикл заново. Ничего не делаем и возвращаемся к новой итерации цикла.
							
								chunk_diapazon_start = Line_diapazon_start;
								chunk_diapazon_end = chunk_diapazon_start + size_SplitSubstr - 1;

								continue;
							}
							else
							{
								if (tail_size == size_SplitSubstr)
								{
									//Значит до конца файла - умещается или только разделитель или какая то полезная данная.

									chunk_diapazon_start = Line_diapazon_start;
									chunk_diapazon_end = chunk_diapazon_start + size_SplitSubstr - 1;

									continue;
								}
								else
								{
									//Значит до конца файла - не умещается разделитель, то есть те байты, что остались не могут быть разделитлем, значит это полезные данные для Line-строки, занесем их в вектор, как Line-строку.


									//------------------------------------------------------------------------------
						            //Прочитаем этот диапазон из файла:

									if (number_Line == 0 || number_Line > add_Line_cntr)
									{
										vec__SplitLine_result.emplace_back();

										res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_start, File_size);

										return res;
									}
									else
									{
										return result_flag::OK;
									}
									//------------------------------------------------------------------------------
								}
							}


						}
					}
					else
					{
						//Значит данных для копирования Line-строки нет - то есть - это ситуация, когда найденный разделитель первый в файле и до него нет никаких данных или это идущие подряд разделители, между который так же нет полезных данных.
					    //Просто смешаем диапазон чанка на один влево:

						chunk_diapazon_start = chunk_diapazon_start + size_SplitSubstr;
						chunk_diapazon_end   = chunk_diapazon_end + size_SplitSubstr;
						
						Line_diapazon_start = chunk_diapazon_start;

						if (chunk_diapazon_end > File_size)
						{
							//Значит вышли за пределы файла, НО...

							const long long tail = (File_size - chunk_diapazon_start + 1);

							if (tail > 0)
							{
								//Значит, что хоть chunk_diapazon_end и вышел за пределы файла, но chunk_diapazon_start - еще находится в пределах файла и значит еще есть байты для обработки:

								if (tail > size_SplitSubstr)
								{
									//Значит до конца файла - еще умещается, как сам разделитель так и полезные байты между ним. Поэтому просто повторяем стандартный цикл заново. Но корректируем "chunk_diapazon_end":

									chunk_diapazon_end = File_size;

									continue;
								}
								else
								{
									if (tail == size_SplitSubstr)
									{
										//Значит до конца файла - умещается или только разделитель или какая то полезная данная.

										continue;
									}
									else
									{
										//Значит до конца файла - не умещается разделитель, то есть те байты, что остались не могут быть разделитлем, значит это полезные данные для Line-строки.

										if (Line_diapazon_start != 0)
										{


											//------------------------------------------------------------------------------
											//Прочитаем этот диапазон из файла:

											if (number_Line == 0 || number_Line > add_Line_cntr)
											{
												vec__SplitLine_result.emplace_back();

												res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_start, File_size);

												return res;
											}
											else
											{
												return result_flag::OK;
											}
											//------------------------------------------------------------------------------
										}
										else
										{
											return result_flag::Line_NotFound;
										}
									}
								}

							}
							else
							{
								if (save_size < vec__SplitLine_result.size())
								{
									return result_flag::OK;
								}
								else
								{
									return result_flag::Line_NotFound;
								}
							}

						}
						else
						{
							Line_diapazon_start = chunk_diapazon_start;

							continue;
						}
					}

				}
				else
				{
					//Значит прочитанный диапазон из файла - это Не разделитель: 

					chunk_diapazon_start = chunk_diapazon_start + 1;
					chunk_diapazon_end   = chunk_diapazon_end + 1;

					if (chunk_diapazon_end > File_size)
					{
						//Значит вышли за пределы файла, и теперь, если "Line_diapazon_start" не равен нулю, то есть ранее был найден разделитель, то в диапазоне от Line_diapazon_start до File_size находится последняя Line-строка, скопируем ее.
						
						if (Line_diapazon_start != 0)
						{
							//------------------------------------------------------------------------------
                            //Прочитаем этот диапазон из файла:

							if (number_Line == 0 || number_Line > add_Line_cntr)
							{
								vec__SplitLine_result.emplace_back();

								res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_start, File_size);

								return res;
							}
							else
							{
								return result_flag::OK;
							}
							//------------------------------------------------------------------------------
						}
						else
						{
							return result_flag::Line_NotFound;
						}

					}

				}


			}
			//-----------------------------------------------------------------------------------------------

		}


		//***************************************************************************************************************************************************************


	}
	template<typename T> const result_flag read__SplitLine_From_Begin(const T& FullPath_name, const char* poiter_to_SplitSubstr, const size_t size_SplitSubstr, std::vector<std::string>& vec__SplitLine_result, const size_t number_Line)
	{

		Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false);


		//-------------------------------------------------
		result_flag res = open_stream();

		if (res != result_flag::OK)
		{
			return res;
		}
		//-------------------------------------------------




		//----------------------Определим размер файла:---------------------------
		fstream_.seekg(0, std::ios::end);   //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		size_t File_size = fstream_.tellg();    //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.

		if (File_size == 0)
		{
			ErrorName = "read__SplitLine_From_Begin:File_empty";
			return result_flag::File_empty;
		}

		File_size = File_size - 1;
		//------------------------------------------------------------------------




		//------------------------------------------
		if (size_SplitSubstr > (File_size + 1))
		{
			return result_flag::Line_NotFound;
		}
		//------------------------------------------


		const size_t save_size = vec__SplitLine_result.size();



		//***************************************************************************************************************************************************************

		//--------------------------------------------------
		std::string chunk_string;

		size_t chunk_diapazon_start = 0;
		size_t chunk_diapazon_end = size_SplitSubstr - 1;

		long long Line_diapazon_start = 0;
		long long Line_diapazon_end = 0;

		size_t add_Line_cntr = 0;
		//--------------------------------------------------

		for (;;)
		{
			//-----------------------------------------------------------------------------------------------
			chunk_string.resize(0);

			res = Run_Read_PartFile_to_StringBack__(chunk_string, chunk_diapazon_start, chunk_diapazon_end);

			if (res != result_flag::OK)
			{
				return res;
			}
			else
			{

				if (chunk_string.compare(poiter_to_SplitSubstr) == 0)
				{
					//Значит прочитанный диапазон из файла - это разделитель:

					const size_t pos_delimeter = chunk_diapazon_start;   //Позиция в файле найденного разделителя.

					Line_diapazon_end = pos_delimeter - 1;


					if (Line_diapazon_end >= Line_diapazon_start)
					{
						//Значит есть данные для копирования их как Line-строки:

						//------------------------------------------------------------------------------
						//Прочитаем этот диапазон из файла:

						if (number_Line == 0 || number_Line > add_Line_cntr)
						{
							vec__SplitLine_result.emplace_back();

							res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_start, Line_diapazon_end);

							if (res != result_flag::OK)
							{
								return res;
							}
						}
						else
						{
							return result_flag::OK;
						}

						add_Line_cntr++;
						//------------------------------------------------------------------------------


						Line_diapazon_start = pos_delimeter + size_SplitSubstr;    //Устанавливаем новую стартовую позицию для чтения следующей Line-строки из файла.


						if (Line_diapazon_start > File_size)
						{
							//Значит вышли за пределы файла и все Line-строки уже сохранены.

							return result_flag::OK;
						}
						else
						{
							//Значит еще есть байты до конца файла:

							const long long tail_size = File_size - Line_diapazon_start + 1;     //Сколько байт осталось от байта следующего сразу за разделителем до конца файла.

							if (tail_size > size_SplitSubstr)
							{
								//Значит до конца файла - еще умещается, как сам разделитель так и полезные байты между ним. Поэтому просто повторяем стандартный цикл заново. Ничего не делаем и возвращаемся к новой итерации цикла.

								chunk_diapazon_start = Line_diapazon_start;
								chunk_diapazon_end = chunk_diapazon_start + size_SplitSubstr - 1;

								continue;
							}
							else
							{
								if (tail_size == size_SplitSubstr)
								{
									//Значит до конца файла - умещается или только разделитель или какая то полезная данная.

									chunk_diapazon_start = Line_diapazon_start;
									chunk_diapazon_end = chunk_diapazon_start + size_SplitSubstr - 1;

									continue;
								}
								else
								{
									//Значит до конца файла - не умещается разделитель, то есть те байты, что остались не могут быть разделитлем, значит это полезные данные для Line-строки, занесем их в вектор, как Line-строку.


									//------------------------------------------------------------------------------
									//Прочитаем этот диапазон из файла:

									if (number_Line == 0 || number_Line > add_Line_cntr)
									{
										vec__SplitLine_result.emplace_back();

										res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_start, File_size);

										return res;
									}
									else
									{
										return result_flag::OK;
									}
									//------------------------------------------------------------------------------
								}
							}


						}
					}
					else
					{
						//Значит данных для копирования Line-строки нет - то есть - это ситуация, когда найденный разделитель первый в файле и до него нет никаких данных или это идущие подряд разделители, между который так же нет полезных данных.
						//Просто смешаем диапазон чанка на один влево:

						chunk_diapazon_start = chunk_diapazon_start + size_SplitSubstr;
						chunk_diapazon_end = chunk_diapazon_end + size_SplitSubstr;

						Line_diapazon_start = chunk_diapazon_start;

						if (chunk_diapazon_end > File_size)
						{
							//Значит вышли за пределы файла, НО...

							const long long tail = (File_size - chunk_diapazon_start + 1);

							if (tail > 0)
							{
								//Значит, что хоть chunk_diapazon_end и вышел за пределы файла, но chunk_diapazon_start - еще находится в пределах файла и значит еще есть байты для обработки:

								if (tail > size_SplitSubstr)
								{
									//Значит до конца файла - еще умещается, как сам разделитель так и полезные байты между ним. Поэтому просто повторяем стандартный цикл заново. Но корректируем "chunk_diapazon_end":

									chunk_diapazon_end = File_size;

									continue;
								}
								else
								{
									if (tail == size_SplitSubstr)
									{
										//Значит до конца файла - умещается или только разделитель или какая то полезная данная.

										continue;
									}
									else
									{
										//Значит до конца файла - не умещается разделитель, то есть те байты, что остались не могут быть разделитлем, значит это полезные данные для Line-строки.

										if (Line_diapazon_start != 0)
										{


											//------------------------------------------------------------------------------
											//Прочитаем этот диапазон из файла:

											if (number_Line == 0 || number_Line > add_Line_cntr)
											{
												vec__SplitLine_result.emplace_back();

												res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_start, File_size);

												return res;
											}
											else
											{
												return result_flag::OK;
											}
											//------------------------------------------------------------------------------
										}
										else
										{
											return result_flag::Line_NotFound;
										}
									}
								}

							}
							else
							{
								if (save_size < vec__SplitLine_result.size())
								{
									return result_flag::OK;
								}
								else
								{
									return result_flag::Line_NotFound;
								}
							}

						}
						else
						{
							Line_diapazon_start = chunk_diapazon_start;

							continue;
						}
					}

				}
				else
				{
					//Значит прочитанный диапазон из файла - это Не разделитель: 

					chunk_diapazon_start = chunk_diapazon_start + 1;
					chunk_diapazon_end = chunk_diapazon_end + 1;

					if (chunk_diapazon_end > File_size)
					{
						//Значит вышли за пределы файла, и теперь, если "Line_diapazon_start" не равен нулю, то есть ранее был найден разделитель, то в диапазоне от Line_diapazon_start до File_size находится последняя Line-строка, скопируем ее.

						if (Line_diapazon_start != 0)
						{
							//------------------------------------------------------------------------------
							//Прочитаем этот диапазон из файла:

							if (number_Line == 0 || number_Line > add_Line_cntr)
							{
								vec__SplitLine_result.emplace_back();

								res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_start, File_size);

								return res;
							}
							else
							{
								return result_flag::OK;
							}
							//------------------------------------------------------------------------------
						}
						else
						{
							return result_flag::Line_NotFound;
						}

					}

				}


			}
			//-----------------------------------------------------------------------------------------------

		}


		//***************************************************************************************************************************************************************


	}

	template<typename T> const result_flag read__SplitLine_From_End(const T& path_name, const T& file_name, const char* poiter_to_SplitSubstr, const size_t size_SplitSubstr, std::vector<std::string>& vec__SplitLine_result, const size_t number_Line)
	{

		Check_for_SetNewPath_and_CheckStreamClose<T>(path_name, file_name, false);


		//-------------------------------------------------
		result_flag res = open_stream();

		if (res != result_flag::OK)
		{
			return res;
		}
		//-------------------------------------------------




		//----------------------Определим размер файла:---------------------------
		fstream_.seekg(0, std::ios::end);   //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		size_t File_size = fstream_.tellg();    //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.

		if (File_size == 0)
		{
			ErrorName = "read__SplitLine_From_Begin:File_empty";
			return result_flag::File_empty;
		}

		File_size = File_size - 1;
		//------------------------------------------------------------------------




		//------------------------------------------
		if (size_SplitSubstr > (File_size + 1))
		{
			return result_flag::Line_NotFound;
		}
		//------------------------------------------


		const size_t save_size = vec__SplitLine_result.size();



		//***************************************************************************************************************************************************************

		//--------------------------------------------------
		std::string chunk_string;

		long long chunk_diapazon_start = File_size;
		long long chunk_diapazon_end   = chunk_diapazon_start - size_SplitSubstr + 1;

		long long Line_diapazon_start = File_size;
		long long Line_diapazon_end   = File_size;

		size_t add_Line_cntr = 0;
		//--------------------------------------------------

		for (;;)
		{
			//-----------------------------------------------------------------------------------------------
			chunk_string.resize(0);

			res = Run_Read_PartFile_to_StringBack__(chunk_string, chunk_diapazon_end, chunk_diapazon_start);

			if (res != result_flag::OK)
			{
				return res;
			}
			else
			{

				if (chunk_string.compare(poiter_to_SplitSubstr) == 0)
				{
					//Значит прочитанный диапазон из файла - это разделитель:

					const size_t pos_delimeter = chunk_diapazon_start;   //Позиция в файле найденного разделителя.

					Line_diapazon_end = pos_delimeter + 1; 


					if (Line_diapazon_end <= Line_diapazon_start)
					{
						//Значит есть данные для копирования их как Line-строки:

						//------------------------------------------------------------------------------
						//Прочитаем этот диапазон из файла:

						if (number_Line == 0 || number_Line > add_Line_cntr)
						{
							vec__SplitLine_result.emplace_back();

							res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_end, Line_diapazon_start);

							if (res != result_flag::OK)
							{
								return res;
							}
						}
						else
						{
							return result_flag::OK;
						}

						add_Line_cntr++;
						//------------------------------------------------------------------------------


						Line_diapazon_start = pos_delimeter - size_SplitSubstr;    //Устанавливаем новую стартовую позицию для чтения следующей Line-строки из файла.


						if (Line_diapazon_start < 0)
						{
							//Значит вышли за пределы файла и все Line-строки уже сохранены.

							return result_flag::OK;
						}
						else
						{
							//Значит еще есть байты до конца файла:

							const long long tail_size = Line_diapazon_start + 1;     //Сколько байт осталось от байта следующего сразу за разделителем до конца файла.

							if (tail_size > size_SplitSubstr)
							{
								//Значит до конца файла - еще умещается, как сам разделитель так и полезные байты между ним. Поэтому просто повторяем стандартный цикл заново. Ничего не делаем и возвращаемся к новой итерации цикла.

								chunk_diapazon_start = Line_diapazon_start;
								chunk_diapazon_end   = chunk_diapazon_start - size_SplitSubstr + 1;

								continue;
							}
							else
							{
								if (tail_size == size_SplitSubstr)
								{
									//Значит до конца файла - умещается или только разделитель или какая то полезная данная.

									chunk_diapazon_start = Line_diapazon_start;
									chunk_diapazon_end   = chunk_diapazon_start - size_SplitSubstr + 1;

									continue;
								}
								else
								{
									//Значит до конца файла - не умещается разделитель, то есть те байты, что остались не могут быть разделитлем, значит это полезные данные для Line-строки, занесем их в вектор, как Line-строку.


									//------------------------------------------------------------------------------
									//Прочитаем этот диапазон из файла:

									if (number_Line == 0 || number_Line > add_Line_cntr)
									{
										vec__SplitLine_result.emplace_back();

										res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), 0, Line_diapazon_start);

										return res;
									}
									else
									{
										return result_flag::OK;
									}
									//------------------------------------------------------------------------------
								}
							}


						}
					}
					else
					{
						//Значит данных для копирования Line-строки нет - то есть - это ситуация, когда найденный разделитель первый в файле и до него нет никаких данных или это идущие подряд разделители, между который так же нет полезных данных.
						//Просто смешаем диапазон чанка на один влево:

						chunk_diapazon_start = chunk_diapazon_start - size_SplitSubstr;
						chunk_diapazon_end   = chunk_diapazon_end   - size_SplitSubstr;

						Line_diapazon_start = chunk_diapazon_start;

						if (chunk_diapazon_end < 0)
						{
							//Значит вышли за пределы файла, НО...

							const long long tail = (chunk_diapazon_start + 1);

							if (tail > 0)
							{
								//Значит, что хоть chunk_diapazon_end и вышел за пределы файла, но chunk_diapazon_start - еще находится в пределах файла и значит еще есть байты для обработки:

								if (tail > size_SplitSubstr)
								{
									//Значит до конца файла - еще умещается, как сам разделитель так и полезные байты между ним. Поэтому просто повторяем стандартный цикл заново. Но корректируем "chunk_diapazon_end":

									chunk_diapazon_end = 0;

									continue;
								}
								else
								{
									if (tail == size_SplitSubstr)
									{
										//Значит до конца файла - умещается или только разделитель или какая то полезная данная.

										continue;
									}
									else
									{
										//Значит до конца файла - не умещается разделитель, то есть те байты, что остались не могут быть разделитлем, значит это полезные данные для Line-строки.

										if (Line_diapazon_start != File_size)
										{


											//------------------------------------------------------------------------------
											//Прочитаем этот диапазон из файла:

											if (number_Line == 0 || number_Line > add_Line_cntr)
											{
												vec__SplitLine_result.emplace_back();

												res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), 0, Line_diapazon_start);

												return res;
											}
											else
											{
												return result_flag::OK;
											}
											//------------------------------------------------------------------------------
										}
										else
										{
											return result_flag::Line_NotFound;
										}
									}
								}

							}
							else
							{
								if (save_size < vec__SplitLine_result.size())
								{
									return result_flag::OK;
								}
								else
								{
									return result_flag::Line_NotFound;
								}
							}

						}
						else
						{
							Line_diapazon_start = chunk_diapazon_start;

							continue;
						}
					}

				}
				else
				{
					//Значит прочитанный диапазон из файла - это Не разделитель: 

					chunk_diapazon_start = chunk_diapazon_start - 1;
					chunk_diapazon_end   = chunk_diapazon_end   - 1;

					if (chunk_diapazon_end < 0)
					{
						//Значит вышли за пределы файла, и теперь, если "Line_diapazon_start" не равен нулю, то есть ранее был найден разделитель, то в диапазоне от Line_diapazon_start до File_size находится последняя Line-строка, скопируем ее.

						if (Line_diapazon_start != File_size)
						{
							//------------------------------------------------------------------------------
							//Прочитаем этот диапазон из файла:

							if (number_Line == 0 || number_Line > add_Line_cntr)
							{
								vec__SplitLine_result.emplace_back();

								res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), 0, Line_diapazon_start);

								return res;
							}
							else
							{
								return result_flag::OK;
							}
							//------------------------------------------------------------------------------
						}
						else
						{
							return result_flag::Line_NotFound;
						}

					}

				}


			}
			//-----------------------------------------------------------------------------------------------

		}


		//***************************************************************************************************************************************************************


	}
	template<typename T> const result_flag read__SplitLine_From_End(const T& FullPath_name, const char* poiter_to_SplitSubstr, const size_t size_SplitSubstr, std::vector<std::string>& vec__SplitLine_result, const size_t number_Line)
	{

		Check_for_SetNewPath_and_CheckStreamClose<T>(FullPath_name, false);


		//-------------------------------------------------
		result_flag res = open_stream();

		if (res != result_flag::OK)
		{
			return res;
		}
		//-------------------------------------------------




		//----------------------Определим размер файла:---------------------------
		fstream_.seekg(0, std::ios::end);   //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		size_t File_size = fstream_.tellg();    //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.

		if (File_size == 0)
		{
			ErrorName = "read__SplitLine_From_Begin:File_empty";
			return result_flag::File_empty;
		}

		File_size = File_size - 1;
		//------------------------------------------------------------------------




		//------------------------------------------
		if (size_SplitSubstr > (File_size + 1))
		{
			return result_flag::Line_NotFound;
		}
		//------------------------------------------


		const size_t save_size = vec__SplitLine_result.size();



		//***************************************************************************************************************************************************************

		//--------------------------------------------------
		std::string chunk_string;

		long long chunk_diapazon_start = File_size;
		long long chunk_diapazon_end = chunk_diapazon_start - size_SplitSubstr + 1;

		long long Line_diapazon_start = File_size;
		long long Line_diapazon_end = File_size;

		size_t add_Line_cntr = 0;
		//--------------------------------------------------

		for (;;)
		{
			//-----------------------------------------------------------------------------------------------
			chunk_string.resize(0);

			res = Run_Read_PartFile_to_StringBack__(chunk_string, chunk_diapazon_end, chunk_diapazon_start);

			if (res != result_flag::OK)
			{
				return res;
			}
			else
			{

				if (chunk_string.compare(poiter_to_SplitSubstr) == 0)
				{
					//Значит прочитанный диапазон из файла - это разделитель:

					const size_t pos_delimeter = chunk_diapazon_start;   //Позиция в файле найденного разделителя.

					Line_diapazon_end = pos_delimeter + 1;


					if (Line_diapazon_end <= Line_diapazon_start)
					{
						//Значит есть данные для копирования их как Line-строки:

						//------------------------------------------------------------------------------
						//Прочитаем этот диапазон из файла:

						if (number_Line == 0 || number_Line > add_Line_cntr)
						{
							vec__SplitLine_result.emplace_back();

							res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), Line_diapazon_end, Line_diapazon_start);

							if (res != result_flag::OK)
							{
								return res;
							}
						}
						else
						{
							return result_flag::OK;
						}

						add_Line_cntr++;
						//------------------------------------------------------------------------------


						Line_diapazon_start = pos_delimeter - size_SplitSubstr;    //Устанавливаем новую стартовую позицию для чтения следующей Line-строки из файла.


						if (Line_diapazon_start < 0)
						{
							//Значит вышли за пределы файла и все Line-строки уже сохранены.

							return result_flag::OK;
						}
						else
						{
							//Значит еще есть байты до конца файла:

							const long long tail_size = Line_diapazon_start + 1;     //Сколько байт осталось от байта следующего сразу за разделителем до конца файла.

							if (tail_size > size_SplitSubstr)
							{
								//Значит до конца файла - еще умещается, как сам разделитель так и полезные байты между ним. Поэтому просто повторяем стандартный цикл заново. Ничего не делаем и возвращаемся к новой итерации цикла.

								chunk_diapazon_start = Line_diapazon_start;
								chunk_diapazon_end = chunk_diapazon_start - size_SplitSubstr + 1;

								continue;
							}
							else
							{
								if (tail_size == size_SplitSubstr)
								{
									//Значит до конца файла - умещается или только разделитель или какая то полезная данная.

									chunk_diapazon_start = Line_diapazon_start;
									chunk_diapazon_end = chunk_diapazon_start - size_SplitSubstr + 1;

									continue;
								}
								else
								{
									//Значит до конца файла - не умещается разделитель, то есть те байты, что остались не могут быть разделитлем, значит это полезные данные для Line-строки, занесем их в вектор, как Line-строку.


									//------------------------------------------------------------------------------
									//Прочитаем этот диапазон из файла:

									if (number_Line == 0 || number_Line > add_Line_cntr)
									{
										vec__SplitLine_result.emplace_back();

										res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), 0, Line_diapazon_start);

										return res;
									}
									else
									{
										return result_flag::OK;
									}
									//------------------------------------------------------------------------------
								}
							}


						}
					}
					else
					{
						//Значит данных для копирования Line-строки нет - то есть - это ситуация, когда найденный разделитель первый в файле и до него нет никаких данных или это идущие подряд разделители, между который так же нет полезных данных.
						//Просто смешаем диапазон чанка на один влево:

						chunk_diapazon_start = chunk_diapazon_start - size_SplitSubstr;
						chunk_diapazon_end = chunk_diapazon_end - size_SplitSubstr;

						Line_diapazon_start = chunk_diapazon_start;

						if (chunk_diapazon_end < 0)
						{
							//Значит вышли за пределы файла, НО...

							const long long tail = (chunk_diapazon_start + 1);

							if (tail > 0)
							{
								//Значит, что хоть chunk_diapazon_end и вышел за пределы файла, но chunk_diapazon_start - еще находится в пределах файла и значит еще есть байты для обработки:

								if (tail > size_SplitSubstr)
								{
									//Значит до конца файла - еще умещается, как сам разделитель так и полезные байты между ним. Поэтому просто повторяем стандартный цикл заново. Но корректируем "chunk_diapazon_end":

									chunk_diapazon_end = 0;

									continue;
								}
								else
								{
									if (tail == size_SplitSubstr)
									{
										//Значит до конца файла - умещается или только разделитель или какая то полезная данная.

										continue;
									}
									else
									{
										//Значит до конца файла - не умещается разделитель, то есть те байты, что остались не могут быть разделитлем, значит это полезные данные для Line-строки.

										if (Line_diapazon_start != File_size)
										{


											//------------------------------------------------------------------------------
											//Прочитаем этот диапазон из файла:

											if (number_Line == 0 || number_Line > add_Line_cntr)
											{
												vec__SplitLine_result.emplace_back();

												res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), 0, Line_diapazon_start);

												return res;
											}
											else
											{
												return result_flag::OK;
											}
											//------------------------------------------------------------------------------
										}
										else
										{
											return result_flag::Line_NotFound;
										}
									}
								}

							}
							else
							{
								if (save_size < vec__SplitLine_result.size())
								{
									return result_flag::OK;
								}
								else
								{
									return result_flag::Line_NotFound;
								}
							}

						}
						else
						{
							Line_diapazon_start = chunk_diapazon_start;

							continue;
						}
					}

				}
				else
				{
					//Значит прочитанный диапазон из файла - это Не разделитель: 

					chunk_diapazon_start = chunk_diapazon_start - 1;
					chunk_diapazon_end = chunk_diapazon_end - 1;

					if (chunk_diapazon_end < 0)
					{
						//Значит вышли за пределы файла, и теперь, если "Line_diapazon_start" не равен нулю, то есть ранее был найден разделитель, то в диапазоне от Line_diapazon_start до File_size находится последняя Line-строка, скопируем ее.

						if (Line_diapazon_start != File_size)
						{
							//------------------------------------------------------------------------------
							//Прочитаем этот диапазон из файла:

							if (number_Line == 0 || number_Line > add_Line_cntr)
							{
								vec__SplitLine_result.emplace_back();

								res = Run_Read_PartFile_to_StringBack__(vec__SplitLine_result.back(), 0, Line_diapazon_start);

								return res;
							}
							else
							{
								return result_flag::OK;
							}
							//------------------------------------------------------------------------------
						}
						else
						{
							return result_flag::Line_NotFound;
						}

					}

				}


			}
			//-----------------------------------------------------------------------------------------------

		}


		//***************************************************************************************************************************************************************


	}
	//**************************************************************************************ЧТЕНИЕ ИЗ ФАЙЛА SPLIT-LINE`ом:Конец***********************************************************************




private:

	//--------------------------------------------
	std::filesystem::path FS_path;
	
	std::fstream          fstream_;

	std::string           ErrorName;
	//--------------------------------------------

	//--------------------------------------------
	std::filesystem::path FS_check;
	bool PreClear_flag = false;
	//--------------------------------------------




    //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	inline const result_flag open_stream()
	{

		if (fstream_.is_open() == false)
		{
			//Значит поток на данный момент закрыт, откроем его:


			//----------------------------------------------------------
			fstream_.open(FS_path, std::ios::binary | std::ios_base::out | std::ios_base::in);  //Открываем сразу для Чтения и Записи чтобы не париться.

			//PS: при попытке открыть поток только для записи - fstream_.open(FS_path, std::ios::binary | std::ios_base::out); - std::ios_base::out открывается файл для записи - удаляя из него нахуй все содержимое. Доабвление std::ios_base::app или  std::ios_base::in - решает эту "проблему"
			//----------------------------------------------------------


			//------------------------------------------------------------------
			return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
			//-------------------------------------------------------------------

		}
		else
		{
			if (PreClear_flag == true)
			{
				//Значит предудыщий режим был - режим Записи данных в файл с предварительным его обнулением. Закроем поток, и откроем занового со "стандартными параметрами":


				PreClear_flag = false;  //Сбрасываем.


				fstream_.close();



				//----------------------------------------------------------
				fstream_.open(FS_path, std::ios::binary | std::ios_base::out | std::ios_base::in);  //Открываем сразу для Чтения и Записи чтобы не париться.

				//PS: при попытке открыть поток только для записи - fstream_.open(FS_path, std::ios::binary | std::ios_base::out); - std::ios_base::out открывается файл для записи - удаляя из него нахуй все содержимое. Доабвление std::ios_base::app или  std::ios_base::in - решает эту "проблему"
				//----------------------------------------------------------


				//------------------------------------------------------------------
				return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
				//-------------------------------------------------------------------
			}
			else
			{
				return result_flag::OK;     //Значит ничего делать не надо, поток и так открыт уже в нужном режиме.
			}
		}

	}
	inline const result_flag open_stream_PreClear_to_Write()
	{

		PreClear_flag = true;  //Ставим флаг, что открываем файл для Записи в режиме обнуления всех данных файла.


		//------------------------------------------
		if (fstream_.is_open() == true)
		{
			//Значит поток на данный момент открыт, закроем его, чтобы открыть поток для записи с обнулением всего содержимого:

			fstream_.close();
		}
		//------------------------------------------
		
		//----------------------------------------------------------
		fstream_.open(FS_path, std::ios::binary | std::ios_base::out);  //Открываем  для  Записи с обнулением всего файла.

		//PS: при попытке открыть поток только для записи - fstream_.open(FS_path, std::ios::binary | std::ios_base::out); - std::ios_base::out открывается файл для записи - удаляя из него все содержимое. Доабвление std::ios_base::app или  std::ios_base::in - решает эту "проблему"
		//----------------------------------------------------------


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------

	}




	//----------------------------------------------------------------------
	inline const result_flag Run_Write__to_PreClear_File__(const char* char_p, const size_t ByteSize_for_write)
	{
		
		//-------------------------------------------------------------------------------------------------
		fstream_.seekp(0, std::ios::beg);   //seekp - устанавливает курсор в файле при Записи

		fstream_.write(char_p, ByteSize_for_write);      //соотвесвенно запишем все байты из указаетля размером "ByteSize_for_write" в файл.
		//-------------------------------------------------------------------------------------------------


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
		
	}
	//----------------------------------------------------------------------
	//----------------------------------------------------------------------
	inline const result_flag Run_Write__to_SelectPos_File__(const char* char_p, const size_t ByteSize_for_write, const size_t Pos_in_File)
	{

		//-------------------------------------------------------------------------------------------------
		fstream_.seekp(Pos_in_File, std::ios::beg);   //seekp - устанавливает курсор в файле при Записи

		fstream_.write(char_p, ByteSize_for_write);      //соотвесвенно запишем все байты из указаетля размером "ByteSize_for_write" в файл.
		//-------------------------------------------------------------------------------------------------


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------

	}
	inline const result_flag Run_Write__to_SelectPos_File__OffsetEnd__(const char* char_p, const size_t ByteSize_for_write, const size_t offset_from_end)
	{

		//-------------------------------------------------------------------------------------------------
		fstream_.seekp(-1 + offset_from_end, std::ios::end);               //seekp - устанавливает курсор в файле при Записи. Устанавливаем строго на последний байт в файле.

		fstream_.write(char_p, ByteSize_for_write);      //соотвесвенно запишем все байты из указаетля размером "ByteSize_for_write" в файл.
		//-------------------------------------------------------------------------------------------------


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------

	}
	//----------------------------------------------------------------------



	//---------------------------------------------------------------------------------------------
	const result_flag Run_Write_to_PreClearFile(const char* char_p, const size_t ByteSize_for_write)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream_PreClear_to_Write();  //Открываем поток до указанного файла с обнулением всего файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт:

			return Run_Write__to_PreClear_File__(char_p, ByteSize_for_write);  //Записываем в файл.
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------
	
	}
	//---------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------
	const result_flag Run_Write__to_SelectPos_File(const char* char_p, const size_t ByteSize_for_write, const size_t Pos_in_File)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream();  //Открываем поток до указанного файла с обнулением всего файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт:

			return Run_Write__to_SelectPos_File__(char_p, ByteSize_for_write, Pos_in_File);  //Записываем в файл.
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------

	}
	const result_flag Run_Write__to_SelectPos_File__OffsetEnd(const char* char_p, const size_t ByteSize_for_write, const size_t offset_from_end)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream();  //Открываем поток до указанного файла с обнулением всего файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт:

			return Run_Write__to_SelectPos_File__OffsetEnd__(char_p, ByteSize_for_write, offset_from_end);  //Записываем в файл.
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------

	}
	//---------------------------------------------------------------------------------------------










	//----------------------------------------------------------------------
	inline const result_flag Run_Read_FullFile_to_StringBack__(std::string& string_for_Read)
	{
	
		//-------------------------------------------------------------------------------------------------
		fstream_.seekg(0, std::ios::end);   //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		const size_t current_index = string_for_Read.size();
		
		const size_t File_size = fstream_.tellg();    //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.


		try { string_for_Read.resize(string_for_Read.size() + File_size); } catch (const std::bad_alloc& e) { ErrorName = e.what(); return  result_flag::bad_alloc_error; }  //Выделим в конец место для записи данных из файла.


		fstream_.seekg(0, std::ios::beg);               //перемещаем позицию курсора обратно в начало файла, откуда и будем читать.

		fstream_.read(&(string_for_Read[current_index]), File_size);     // соотвесвенно прочитаем все байты из файла в наш динамически выделнный буффер.
		//-------------------------------------------------------------------------------------------------



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------

	}

	inline const result_flag Run_Read_PartFile_to_StringBack__(std::string& string_for_Read, const size_t PosInFile_beg, const size_t PosInFile_end)
	{

		//PosInFile_beg - номер байта в файле откуда включительно необходимо читать.  Нумерация стандартная первый байт - начинается с нуля.
		//PosInFile_end - номер байта в файле до куда включительно необходимо читать. Нумерация стандартная первый байт - начинается с нуля.


		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t current_index = string_for_Read.size();

		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;

		try { string_for_Read.resize(string_for_Read.size() + size_for_read); } catch (const std::bad_alloc& e) { ErrorName = e.what(); return  result_flag::bad_alloc_error; }      //Выделим в конец место для записи данных из файла.

		fstream_.read(&(string_for_Read[current_index]), size_for_read);     // Читаем.
		//-------------------------------------------------------------------------



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}

	inline const result_flag Run_Read_PartFile_to_StringBack__OffsetEnd__(std::string& string_for_Read, const size_t PosInFile_beg, const size_t offset_from_end)
	{

		//PosInFile_beg - номер байта в файле откуда включительно необходимо читать.  Нумерация стандартная первый байт - начинается с нуля.
		//offset_from_end - Пользовательское смещение от самого послденего байта в файле.


		//-------------------------------------------------------------------------
	
		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************
		
		fstream_.seekg(-1 - offset_from_end, std::ios::end);

		const size_t PosInFile_end = fstream_.tellg();

		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************


		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t current_index = string_for_Read.size();

	
		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;


		try { string_for_Read.resize(string_for_Read.size() + size_for_read); } catch (const std::bad_alloc& e) { ErrorName = e.what(); return  result_flag::bad_alloc_error; }      //Выделим в конец место для записи данных из файла.

		fstream_.read(&(string_for_Read[current_index]), size_for_read);     // Читаем.
		//-------------------------------------------------------------------------



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}
	inline const result_flag Run_Read_PartFile_to_StringBack__DoubleOffsetEnd__(std::string& string_for_Read, const size_t Beg_offset_from_end, const size_t End_offset_from_end)
	{

		//Beg_offset_from_end - начальное смещение слева от Последнего байта.
		//End_offset_from_end - конечное смещение справа от Последнего байта.


		//-------------------------------------------------------------------------

		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************

		fstream_.seekg(-1 - Beg_offset_from_end, std::ios::end);

		const size_t PosInFile_beg = fstream_.tellg();



		fstream_.seekg(-1 - End_offset_from_end, std::ios::end);

		const size_t PosInFile_end = fstream_.tellg();

		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************


		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t current_index = string_for_Read.size();


		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;


		try { string_for_Read.resize(string_for_Read.size() + size_for_read); }
		catch (const std::bad_alloc& e) { ErrorName = e.what(); return  result_flag::bad_alloc_error; }      //Выделим в конец место для записи данных из файла.

		fstream_.read(&(string_for_Read[current_index]), size_for_read);     // Читаем.
		//-------------------------------------------------------------------------



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}
	//----------------------------------------------------------------------
	//----------------------------------------------------------------------
	inline const result_flag Run_Read_FullFile_to_FixSizeCharPointer__(char* CharPointer)
	{

		//-------------------------------------------------------------------------
		fstream_.seekg(0, std::ios::end);                 //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		const size_t File_size = fstream_.tellg();        //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.

		fstream_.seekg(0, std::ios::beg);                //перемещаем позицию курсора обратно в начало файла, откуда и будем читать.

		fstream_.read(CharPointer, File_size);           //соотвесвенно прочитаем все байты из файла с начала указателя.
		//-------------------------------------------------------------------------



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}

	inline const result_flag Run_Read_PartFile_to_FixSizeCharPointer__(char* CharPointer, const size_t PosInFile_beg, const size_t PosInFile_end)
	{

		//PosInFile_beg - номер байта в файле откуда включительно необходимо читать.  Нумерация стандартная первый байт - начинается с нуля.
		//PosInFile_end - номер байта в файле до куда включительно необходимо читать. Нумерация стандартная первый байт - начинается с нуля.


		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;

		fstream_.read(CharPointer, size_for_read);     // Читаем.
		//-------------------------------------------------------------------------



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}
	
	inline const result_flag Run_Read_PartFile_to_FixSizeCharPointer__OffsetEnd__(char* CharPointer, const size_t PosInFile_beg, const size_t offset_from_end, size_t& read_size_ref)
	{

		//PosInFile_beg   - номер байта в файле откуда включительно необходимо читать.  Нумерация стандартная первый байт - начинается с нуля.
		//offset_from_end - Пользовательское смещение от самого послденего байта в файле.



		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************

		fstream_.seekg(-1 - offset_from_end, std::ios::end);

		const size_t PosInFile_end = fstream_.tellg();

		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************



		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;

		fstream_.read(CharPointer, size_for_read);     // Читаем.
		//-------------------------------------------------------------------------



		read_size_ref = size_for_read;



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}
	inline const result_flag Run_Read_PartFile_to_FixSizeCharPointer__DoubleOffsetEnd__(char* CharPointer, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size_ref)
	{

		//Beg_offset_from_end - начальное смещение слева от Последнего байта.
		//End_offset_from_end - конечное смещение справа от Последнего байта.



		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************

		fstream_.seekg(-1 - Beg_offset_from_end, std::ios::end);

		const size_t PosInFile_beg = fstream_.tellg();



		fstream_.seekg(-1 - End_offset_from_end, std::ios::end);

		const size_t PosInFile_end = fstream_.tellg();

		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************



		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;

		fstream_.read(CharPointer, size_for_read);     // Читаем.
		//-------------------------------------------------------------------------



		read_size_ref = size_for_read;



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}
	//----------------------------------------------------------------------
	//----------------------------------------------------------------------
	inline const result_flag Run_Read_FullFile_to_DynamicRawPointer__(char** char_p_p, size_t& read_size_ref)
	{

		//-------------------------------------------------------------------------------------------------
		fstream_.seekg(0, std::ios::end);   //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		const size_t File_size = fstream_.tellg();    //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.

		try { *char_p_p = new char[File_size + 1]; } catch (const std::bad_alloc& e) { ErrorName = e.what(); return  result_flag::bad_alloc_error; }  //Выделяем память. +1 - под завершающий ноль.

		fstream_.seekg(0, std::ios::beg);               //перемещаем позицию курсора обратно в начало файла, откуда и будем читать.

		fstream_.read(*char_p_p, File_size);     // соотвесвенно прочитаем все байты из файла в наш динамически выделнный буффер.
			
		(*char_p_p)[File_size] = 0;
		//-------------------------------------------------------------------------------------------------


		read_size_ref = File_size;


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}

	inline const result_flag Run_Read_PartFile_to_DynamicRawPointer__(char** char_p_p, const size_t PosInFile_beg, const size_t PosInFile_end)
	{

		//PosInFile_beg - номер байта в файле откуда включительно необходимо читать.  Нумерация стандартная первый байт - начинается с нуля.
		//PosInFile_end - номер байта в файле до куда включительно необходимо читать. Нумерация стандартная первый байт - начинается с нуля.


		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;


		try { *char_p_p = new char[size_for_read + 1]; } catch (const std::bad_alloc& e) { ErrorName = e.what(); return  result_flag::bad_alloc_error; }  //Выделяем память. +1 - под завершающий ноль.


		fstream_.read(*char_p_p, size_for_read);     // Читаем.

		(*char_p_p)[size_for_read] = 0;
		//-------------------------------------------------------------------------



		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}

	inline const result_flag Run_Read_PartFile_to_DynamicRawPointer__OffsetEnd__(char** char_p_p, const size_t PosInFile_beg, const size_t offset_from_end, size_t& read_size_ref)
	{

		//PosInFile_beg - номер байта в файле откуда включительно необходимо читать.  Нумерация стандартная первый байт - начинается с нуля.
	    //offset_from_end - Пользовательское смещение от самого послденего байта в файле.



		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************

		fstream_.seekg(-1 - offset_from_end, std::ios::end);

		const size_t PosInFile_end = fstream_.tellg();

		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************



		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;


		try { *char_p_p = new char[size_for_read + 1]; } catch (const std::bad_alloc& e) { ErrorName = e.what(); return  result_flag::bad_alloc_error; }  //Выделяем память. +1 - под завершающий ноль.


		fstream_.read(*char_p_p, size_for_read);     // Читаем.

		(*char_p_p)[size_for_read] = 0;
		//-------------------------------------------------------------------------


		read_size_ref = size_for_read;


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}
	inline const result_flag Run_Read_PartFile_to_DynamicRawPointer__DoubleOffsetEnd__(char** char_p_p, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size_ref)
	{

		//PosInFile_beg - номер байта в файле откуда включительно необходимо читать.  Нумерация стандартная первый байт - начинается с нуля.
		//offset_from_end - Пользовательское смещение от самого послденего байта в файле.



		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************

		fstream_.seekg(-1 - Beg_offset_from_end, std::ios::end);

		const size_t PosInFile_beg = fstream_.tellg();



		fstream_.seekg(-1 - End_offset_from_end, std::ios::end);

		const size_t PosInFile_end = fstream_.tellg();

		//*****************Получим позицию конца файла и применим Пользовательское "offset_from_end" смешение к нему:Начало****************



		//-------------------------------------------------------------------------
		fstream_.seekg(PosInFile_beg, std::ios::beg);   //Смещаем курсор относительно начала файла "std::ios::beg" на значение "PosInFile_beg".

		const size_t size_for_read = PosInFile_end - PosInFile_beg + 1;


		try { *char_p_p = new char[size_for_read + 1]; }
		catch (const std::bad_alloc& e) { ErrorName = e.what(); return  result_flag::bad_alloc_error; }  //Выделяем память. +1 - под завершающий ноль.


		fstream_.read(*char_p_p, size_for_read);     // Читаем.

		(*char_p_p)[size_for_read] = 0;
		//-------------------------------------------------------------------------


		read_size_ref = size_for_read;


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------
	}
	//----------------------------------------------------------------------



	//---------------------------------------------------------------------------------------------
	const result_flag Run_Read_FullFile_to_StringBack(std::string& string_for_read)
	{

			//----------------------------------------------------------------------------------------------
			const result_flag result = open_stream();  //Открываем поток до указанного файла.

			if (result == result_flag::OK)
			{
				//Значит поток успешно открыт или был открыт до этого:

				return Run_Read_FullFile_to_StringBack__(string_for_read);  //Читаем файл целиком в конец "string_for_read".
			}
			else
			{
				return result;  //Ошибка.
			}
			//----------------------------------------------------------------------------------------------

	}

	const result_flag Run_Read_PartFile_to_StringBack(std::string& string_for_read, const size_t PosInFile_beg, const size_t PosInFile_end)
	{

			//----------------------------------------------------------------------------------------------
			const result_flag result = open_stream();  //Открываем поток до указанного файла.

			if (result == result_flag::OK)
			{
				//Значит поток успешно открыт или был открыт до этого:

				return Run_Read_PartFile_to_StringBack__(string_for_read, PosInFile_beg, PosInFile_end);   //Читаем указанную часть файла в конец "string_for_read".
			}
			else
			{
				return result;  //Ошибка.
			}
			//----------------------------------------------------------------------------------------------

	}

	const result_flag Run_Read_PartFile_to_StringBack__OffsetEnd(std::string& string_for_read, const size_t PosInFile_beg, const size_t offset_from_end)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream();  //Открываем поток до указанного файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт или был открыт до этого:

			return Run_Read_PartFile_to_StringBack__OffsetEnd__(string_for_read, PosInFile_beg, offset_from_end);   //Читаем указанную часть файла в конец "string_for_read".
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------

	}
	const result_flag Run_Read_PartFile_to_StringBack__DoubleOffsetEnd(std::string& string_for_read, const size_t Beg_offset_from_end, const size_t End_offset_from_end)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream();  //Открываем поток до указанного файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт или был открыт до этого:

			return Run_Read_PartFile_to_StringBack__DoubleOffsetEnd__(string_for_read, Beg_offset_from_end, End_offset_from_end);   //Читаем указанную часть файла в конец "string_for_read".
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------

	}
	//---------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------
	const result_flag Run_Read_FullFile_to_FixSizeCharPointer(char* CharPointer)
	{

			//----------------------------------------------------------------------------------------------
			const result_flag result = open_stream();  //Открываем поток до указанного файла.

			if (result == result_flag::OK)
			{
				//Значит поток успешно открыт или был открыт до этого:

				return Run_Read_FullFile_to_FixSizeCharPointer__(CharPointer);   //Читаем файл целиком в переданный указатель.
			}
			else
			{
				return result;  //Ошибка.
			}
			//----------------------------------------------------------------------------------------------

	}

	const result_flag Run_Read_PartFile_to_FixSizeCharPointer(char* CharPointer, const size_t PosInFile_beg, const size_t PosInFile_end)
	{

			//----------------------------------------------------------------------------------------------
			const result_flag result = open_stream();  //Открываем поток до указанного файла.

			if (result == result_flag::OK)
			{
				//Значит поток успешно открыт или был открыт до этого:

				return Run_Read_PartFile_to_FixSizeCharPointer__(CharPointer, PosInFile_beg, PosInFile_end);    
			}
			else
			{
				return result;  //Ошибка.
			}
			//----------------------------------------------------------------------------------------------
	}
	
	const result_flag Run_Read_PartFile_to_FixSizeCharPointer__OffsetEnd(char* CharPointer, const size_t PosInFile_beg, const size_t offset_from_end, size_t& read_size)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream();  //Открываем поток до указанного файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт или был открыт до этого:

			return Run_Read_PartFile_to_FixSizeCharPointer__OffsetEnd__(CharPointer, PosInFile_beg, offset_from_end, read_size);    
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------
	}
	const result_flag Run_Read_PartFile_to_FixSizeCharPointer__DoubleOffsetEnd(char* CharPointer, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream();  //Открываем поток до указанного файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт или был открыт до этого:

			return Run_Read_PartFile_to_FixSizeCharPointer__DoubleOffsetEnd__(CharPointer, Beg_offset_from_end, End_offset_from_end, read_size);    
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------
	}
	//---------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------
	const result_flag Run_Read_FullFile_to_DynamicRawPointer(char** char_p_p, size_t& read_size)
	{
			//----------------------------------------------------------------------------------------------
			const result_flag result = open_stream();  //Открываем поток до указанного файла.

			if (result == result_flag::OK)
			{
				//Значит поток успешно открыт или был открыт до этого:

				return Run_Read_FullFile_to_DynamicRawPointer__(char_p_p, read_size);  //Читаем файл целиком в выделенную память.
			}
			else
			{
				return result;  //Ошибка.
			}
			//----------------------------------------------------------------------------------------------

	}

	const result_flag Run_Read_PartFile_to_DynamicRawPointer(char** char_p_p, const size_t PosInFile_beg, const size_t PosInFile_end)
	{

			//----------------------------------------------------------------------------------------------
			const result_flag result = open_stream();  //Открываем поток до указанного файла.

			if (result == result_flag::OK)
			{
				//Значит поток успешно открыт или был открыт до этого:

				return Run_Read_PartFile_to_DynamicRawPointer__(char_p_p, PosInFile_beg, PosInFile_end);   //Читаем указанную часть файла в выделенную память.
			}
			else
			{
				return result;  //Ошибка.
			}
			//----------------------------------------------------------------------------------------------

	}
	
	const result_flag Run_Read_PartFile_to_DynamicRawPointer__OffsetEnd(char** char_p_p, const size_t PosInFile_beg, const size_t offset_from_end, size_t& read_size)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream();  //Открываем поток до указанного файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт или был открыт до этого:

			return Run_Read_PartFile_to_DynamicRawPointer__OffsetEnd__(char_p_p, PosInFile_beg, offset_from_end, read_size);   //Читаем указанную часть файла в выделенную память.
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------

	}
	const result_flag Run_Read_PartFile_to_DynamicRawPointer__DoubleOffsetEnd(char** char_p_p, const size_t Beg_offset_from_end, const size_t End_offset_from_end, size_t& read_size)
	{

		//----------------------------------------------------------------------------------------------
		const result_flag result = open_stream();  //Открываем поток до указанного файла.

		if (result == result_flag::OK)
		{
			//Значит поток успешно открыт или был открыт до этого:

			return Run_Read_PartFile_to_DynamicRawPointer__DoubleOffsetEnd__(char_p_p, Beg_offset_from_end, End_offset_from_end, read_size);   //Читаем указанную часть файла в выделенную память.
		}
		else
		{
			return result;  //Ошибка.
		}
		//----------------------------------------------------------------------------------------------

	}
	//---------------------------------------------------------------------------------------------




	//---------------------------------------------------------------------------------------------
	template<typename T> const result_flag Check_for_SetNewPath_and_CheckStreamClose(const T& path_name, const T& file_name, const bool ForcedClose)
	{

		//-------------------------------------------------------------------------
		if constexpr (std::is_same_v<T, std::string>) 
		{
			try { FS_check = std::filesystem::u8path(path_name + file_name); } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }
		}
		else
		{
			try { FS_check = path_name + file_name; }catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }
		}
		//-------------------------------------------------------------------------

		//---------------------------------------------------1:Проверка на новый путь:Начало-----------------------------------------------------------------------------------
		if (FS_check != FS_path)
		{
			//Значит Пользователь вызвал метод с новый путем, который был до этого, значит закроем поток к предыдущему файлу со старым путем:

			fstream_.close();

			FS_path = std::move(FS_check);  //Перемещаем новый путь в рабочий путь.

			return result_flag::OK;
		}
		//---------------------------------------------------1:Проверка на новый путь:Конец-----------------------------------------------------------------------------------



		//---------------------------------------------------2:Если Пользователь вызовал метод записи в файл с предварительным очишением файла:Начало--------------------------
		if (ForcedClose == true)
		{
			fstream_.close();
		}
		//---------------------------------------------------2:Если Пользователь вызовал метод записи в файл с предварительным очишением файла:Конец--------------------------



		return result_flag::OK;

	}

	template<typename T> const result_flag Check_for_SetNewPath_and_CheckStreamClose(const T& FullPath_name, const bool ForcedClose)
	{


		//-------------------------------------------------------------------------
		if constexpr (std::is_same_v<T, std::string>)
		{
			try { FS_check = std::filesystem::u8path(FullPath_name); } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }
		}
		else
		{
			try { FS_check = FullPath_name; } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }
		}
		//-------------------------------------------------------------------------


		//---------------------------------------------------1:Проверка на новый путь:Начало-----------------------------------------------------------------------------------
		if (FS_check != FS_path)
		{
			//Значит Пользователь вызвал метод с новый путем, который был до этого, значит закроем поток к предыдущему файлу со старым путем:

			fstream_.close();

			FS_path = std::move(FS_check);  //Перемещаем новый путь в рабочий путь.

			return result_flag::OK;
		}
		//---------------------------------------------------1:Проверка на новый путь:Конец-----------------------------------------------------------------------------------



		//---------------------------------------------------2:Если Пользователь вызвал метод записи в файл с предварительным очишением файла:Начало--------------------------
		if (ForcedClose == true)
		{
			fstream_.close();
		}
		//---------------------------------------------------2:Если Пользователь вызвал метод записи в файл с предварительным очишением файла:Конец--------------------------



		return result_flag::OK;

	}
	//---------------------------------------------------------------------------------------------




	//---------------------------------------------------------------------------------------------
	template<typename T> const result_flag Run_get__FilebyteSize(const T& path_name, const T& file_name, size_t& File_size)
	{	
		try { FS_path = path_name + file_name; } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		return get__FileSize(File_size);
	}
	template<typename T> const result_flag Run_get__FilebyteSize__Only_UTF8(const T& path_name, const T& file_name, size_t& File_size)
	{
		try { FS_path = std::filesystem::u8path(path_name + file_name); } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		return get__FileSize(File_size);
	}
	template<typename T> const result_flag Run_get__FilebyteSize(const T& FullPath_name, size_t& File_size)
	{
		try { FS_path = FullPath_name; } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		return get__FileSize(File_size);
	}
	template<typename T> const result_flag Run_get__FilebyteSize__Only_UTF8(const T& FullPath_name, size_t& File_size)
	{
		try { FS_path = std::filesystem::u8path(FullPath_name); } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		return get__FileSize(File_size);
	}

	inline const result_flag get__FileSize(size_t& File_size)
	{

		//------------------------------------------------------------------------------
		if (fstream_.is_open() == true)
		{
			//Значит поток на данный момент открыт, так как очень вероятно он открыт для другого файла, то закроем его:

			fstream_.close();
		}

		fstream_.open(FS_path, std::ios::binary | std::ios_base::in);  //Открываем поток для Чтения.


		fstream_.seekg(0, std::ios::end);   //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		File_size = fstream_.tellg();    //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.
		//------------------------------------------------------------------------------


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------

	}
	//---------------------------------------------------------------------------------------------


	//---------------------------------------------------------------------------------------------
	template<typename T> const result_flag Run_create__EmptyFile(const T& path_name, const T& file_name)
	{
		try { FS_path = path_name + file_name; } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		return create__EmptyFile__();
	}
	template<typename T> const result_flag Run_create__EmptyFile__Only_UTF8(const T& path_name, const T& file_name)
	{
		try { FS_path = std::filesystem::u8path(path_name + file_name); } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		return create__EmptyFile__();
	}
	template<typename T> const result_flag Run_create__EmptyFile(const T& FullPath_name)
	{
		try { FS_path = FullPath_name; } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		return create__EmptyFile__();
	}
	template<typename T> const result_flag Run_create__EmptyFile__Only_UTF8(const T& FullPath_name)
	{
		try { FS_path = std::filesystem::u8path(FullPath_name); } catch (const std::filesystem::filesystem_error& e) { ErrorName = e.what(); return  result_flag::std__FileSystem_error; }

		return create__EmptyFile__();
	}

	inline const result_flag create__EmptyFile__()
	{

		//------------------------------------------------------------------------------
		if (fstream_.is_open() == true)
		{
			//Значит поток на данный момент открыт, так как очень вероятно он открыт для другого файла, то закроем его:

			fstream_.close();
		}

		fstream_.open(FS_path, std::ios::binary | std::ios::out);
		//---------------------------------------------------------------------------


		//----------------------------------------------------------------------------------------------------------------------------------

		fstream_.seekp(0, std::ios::beg);

		fstream_.write("", 0);

		fstream_.close();            // закроем поток до файла.


		//Будет создан пустой файл с нулевым размером

		//----------------------------------------------------------------------------------------------------------------------------------


		//------------------------------------------------------------------
		return error_handler();   //Проверяем на ошибки после вызова метода "fstream_".
		//-------------------------------------------------------------------

	}
	//---------------------------------------------------------------------------------------------




	inline const size_t get__CurrentOpenStream_FileSize_()
	{
		fstream_.seekg(0, std::ios::end);   //seekg - устанавливает курсор в файле при Чтении: первый параметр задает смещение относительно второго параметра: то есть смещение влево или вправо от конечного положения курсора в файле. Устанавливаем курсор в конец файла - для того, чтобы узнать кол-во байт в файле.

		return fstream_.tellg();    //tellg() возвращает значение позиции на котором сейчас находится курсор, то есть в данном случае, курсор поставлен в конец файла и таким образом получилим номер позцию этого курсора, тем самым мы получили кол-во байт в файле, то есть по сути размер данных файла.
	}

	inline const result_flag error_handler()
	{

		//------------------------------------------------------------------
		if (fstream_.good() == true)
		{
			//Значит поток до файла успешно октрылся:

			return result_flag::OK;
		}
		else
		{
			//Значит поток к файл не открылся и выдал ошибку.


			const std::ios::iostate error_flag = fstream_.rdstate();

			//----------------------------------------------------
			if ((error_flag & std::ios::eofbit) == std::ios::eofbit)
			{
				ErrorName = "std::ios::eofbit";

				goto jump;
			}
			else if ((error_flag & std::ios::badbit) == std::ios::badbit)
			{
				ErrorName = "std::ios::badbit";

				goto jump;
			}
			else if ((error_flag & std::ios::failbit) == std::ios::failbit)
			{
				ErrorName = "std::ios::failbit";

				goto jump;
			}
			//----------------------------------------------------


			jump:

			fstream_.clear();  //Сбросим внутрение флаги ошибки.


			stream_close();  //Закрываем поток.


			return result_flag::fstream_error;
		}
		//-------------------------------------------------------------------

	}

};
