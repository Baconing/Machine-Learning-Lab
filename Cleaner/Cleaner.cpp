#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <fstream>

void CleanDir(std::string base_path, std::vector<std::string> excluded_folders, std::vector<std::string> files_to_delete, std::vector<std::string> ext_to_delete) {
	//recursively iterate through the base path and subfolders and delete files
	for (const auto& entry : std::filesystem::directory_iterator(base_path))
	{
		//check if the current path is a directory
		if (entry.is_directory())
		{
			bool skip = false;
			//check if the current directory is in the excluded folders list
			for (auto folder : excluded_folders)
			{
				//check if the current directory is in the excluded folders list
				if (entry.path().filename().string() == folder)
				{
					skip = true;
				}
			}
			if (skip)
			{
				continue;
			}
			else {
				CleanDir(entry.path().string(), excluded_folders, files_to_delete,ext_to_delete);
			}
		}

		//check if the current path is a file
		if (entry.is_regular_file())
		{
			//check if the current file is in the files to delete list
			for (auto file : files_to_delete)
			{
				//check if the current file is in the files to delete list
				if (entry.path().filename().string() == file)
				{
					//delete the file
					std::filesystem::remove(entry.path());
				}
			}

			//check if the current file has an extension that is in the ext to delete list
			for (auto ext : ext_to_delete)
			{
				//check if the current file has an extension that is in the ext to delete list
				if (entry.path().extension().string() == ext)
				{
					//delete the file
					std::filesystem::remove(entry.path());
				}
			}
		}
	}
}

void CopyFiles(std::string basepath,std::vector<std::string> paths, std::string Destenation) {
	for (auto path : paths) {
		//if destenation exists, delete it
		if (std::filesystem::exists(Destenation + "/" + path)) {
			std::filesystem::remove_all(Destenation + "/" + path);
		}
		//copy recursively
		std::filesystem::copy(basepath + "/" + path, Destenation + "/" + path, std::filesystem::copy_options::recursive);
	}
}

int main()
{
	//if the config file doesn't exist, create it
	if (!std::filesystem::exists("config.json"))
	{
		//create the config file
		std::ofstream o("config.json");

		//create the json object
		nlohmann::json j;

		//set the base path
		j["base_path"] = "C:\\Users\\user\\Desktop\\test";

		//set the excluded folders
		j["excluded_folders"] = { "C:\\Users\\user\\Desktop\\test\\test2" };

		//set the files to delete
		j["files_to_delete"] = { "C:\\Users\\user\\Desktop\\test\\test.txt" };

		//write the json object to the config file
		o << j << std::endl;

		//close the config file
		o.close();
	}

	//load config.json
	std::ifstream i("config.json");
	nlohmann::json j;
	i >> j;

	//get the base path
	std::string base_path = j["base_path"];

	//get excluded folders
	std::vector<std::string> excluded_folders = j["excluded_folders"];

	//get files to delete
	std::vector<std::string> files_to_delete = j["files_to_delete"];

	//get extensions to delete
	std::vector<std::string> ext_to_delete = j["ext_to_delete"];

	//recursively iterate through the base path and subfolders and delete files
	CleanDir(base_path, excluded_folders, files_to_delete, ext_to_delete);

	std::vector<std::string> FilesToCopy = j["files_to_copy"];

	std::string Destenation = j["destenation_to_copy"];

	CopyFiles(base_path,FilesToCopy, Destenation);
}