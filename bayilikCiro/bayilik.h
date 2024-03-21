#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>

const unsigned short BAYI_SAYISI = 6;
struct bayi
{
    std::string No;
    // 3 aylik toplam cirolardan olusan yillik ciro dizisi
    double donemCiro[4];
    double yillikCiro;

    void etkinlestir(std::ifstream &read)
    {
        for (size_t i = 0; i < BAYI_SAYISI; i++)
        {
            read >> this[i].No;
            for (size_t j = 0; j < 4; j++)
            {
                this[i].donemCiro[j] = 0.0;
                this[i].yillikCiro = 0.0;
            }
        }
    }

    void verileriAl(std::ifstream &read)
    {
        std::string bayiNo;
        size_t i;
        int ay;
        double tutar;
        read >> bayiNo;
        while (true)
        {
            read >> ay >> tutar;

            // bayi numarasi esit olan bayiligi bulana kadar dondur
            for (i = 0; i < BAYI_SAYISI; i++)
                if (bayiNo != this[i].No)
                    break;

            if (i >= BAYI_SAYISI)
            {
                std::cerr << "Hatali Bayi Numarasi";
            }
            else
            {
                switch (ay)
                {
                case 1 ... 3:
                    this[i].donemCiro[0] += tutar;
                    break;
                case 4 ... 6:
                    this[i].donemCiro[1] += tutar;
                    break;
                case 7 ... 9:
                    this[i].donemCiro[2] += tutar;
                    break;
                default:
                    this[i].donemCiro[3] += tutar;
                    break;
                }
            }

            if (read.eof())
            {
                break;
            }

            read >> bayiNo;
        }
    }

    double donemCiroToplam(size_t donem)
    {
        double toplamCiro = 0.0;

        for (size_t i = 0; i < BAYI_SAYISI; i++)
        {
            toplamCiro += this[i].donemCiro[donem];
        }

        return toplamCiro;
    }

    void yillikCiroHesapla()
    {
        for (size_t i = 0; i < BAYI_SAYISI; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                this[i].yillikCiro += this[i].donemCiro[j];
            }
        }
    }
    void raporYaz(std::ofstream &write)
    {
        write << "=======================Yillik Ciro Raporu=======================" << std::endl
              << std::endl
              << "Bayi    Donem1    Donem2    Donem3    Donem4    Toplam" << std::endl;

        for (size_t i = 0; i < BAYI_SAYISI; i++)
        {
            write << this[i].No;
            for (size_t j = 0; j < 4; j++)
            {
                write << std::setw(10) << this[i].donemCiro[j];
            }
            write << std::setw(10) << this[i].yillikCiro << std::endl;
        }
        write << "Toplam: ";
        double toplamCiro;
        for (size_t i = 0; i < 4; i++)
        {
            toplamCiro += donemCiroToplam(i);
        }
        write << toplamCiro << std::endl;
    }

    void enYuksekCiro(std::ofstream &write)
    {
        int indisMax = 0;
        for (size_t i = 1; i < BAYI_SAYISI; i++)
        {
            if (this[indisMax].yillikCiro < this[i].yillikCiro)
            {
                indisMax = i;
            }
        }
        write << "Bu yilin en yuksek cirolu bayisi: " << this[indisMax].No << std::endl
              << "Yillik cirosu: " << this[indisMax].yillikCiro << std::endl;
    }
};