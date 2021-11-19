#ifndef STREAM_H_
#define STREAM_H_

#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include <io.h>
#include <direct.h>
#include <ostream>

namespace LZ_zip{

    class InputStream{
        public:
            explicit InputStream(std::string filename) : encode_file(filename) {
                if(!encode_file.is_open()){
                    std::cout << "File not open\n";
                }
            }

            template<typename T>
            bool ExchangeOpenFile(T&& temp){
                CloseFile();
                encode_file.open(temp);
            }

            std::string ReadFile(){
                std::ostringstream buf;
                buf << encode_file.rdbuf();
                return buf.str();
                //TODO : Value passing, Want to make features independent.
            }

            void Close(){
                CloseFile();
            }

            ~InputStream(){
                CloseFile();
            }
        private:
            std::fstream encode_file;
            void CloseFile(){
                if(encode_file.is_open())
                    encode_file.close();
            }
    };

    class OutputStream{

    public: 
        static void Delete(std::string filename)
        {
			if (_access(filename.c_str(), 0) == 0)
			{
				std::cout << filename << " exists" << std::endl;
				std::cout << "now delete it" << std::endl;
				int flag = remove(filename.c_str());
				if (flag == 0)
				{
					std::cout << "delete it successfully" << std::endl;
				}
				else {
					std::cout << "delete it errorly" << std::endl;
				}
			}
		}

        public:
            explicit OutputStream(std::string filename) : decode_file(filename, std::ofstream::app) {
				
				
                if(!decode_file.is_open()){
                    std::cout << "File not open.\n";
                }
            }
            template<typename T>
            void WriteFile(T&& temp){
                if(decode_file.is_open()){
                    decode_file << temp;
                }
            }

            template<typename T>
            bool ExchangeOpenFile(T&& temp){
                decode_file.close();
                decode_file.open(temp);
                return decode_file.is_open();
            }

            void Close(){
                CloseFile();
            }

            ~OutputStream(){
                CloseFile();
            }

        private:
            std::ofstream decode_file;
            void CloseFile(){
                if(decode_file.is_open())
                    decode_file.close();
            }
    };
}


#endif