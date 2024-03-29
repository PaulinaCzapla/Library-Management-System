#include "FileLibrary.h"

FileLibrary::FileLibrary(std::string filename_) : File(filename_) {}

void FileLibrary::read(Library& library)// ID imie nazwisko tytul data dostep
{
	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::in);
	char space[2];
	int counter_books = 0, counter_cds = 0, counter_movies = 0;
	int tmpcounter;

	if (this->check(file))
	{
		std::string ID, name, surname, date, title, tmp, tmp2 = "", lib_sign;
		bool is_available, digit;
		int i = 0;
		while (!file.eof())
		{
			if (file >> ID >> name)
			{
				i++;
				digit = false;
				tmp = name;
				for (int j = 0; ; j++)
				{
					file >> tmp;
					for (char ch : tmp)
						if (isdigit(ch))
						{
							digit = true;
							date = tmp;
							break;
						}

					if (digit)
						break;

					name = name + " " + tmp;
				}
				file >> is_available;
				file.read(space, 1);
				getline(file, title);

				date = "01.01." + date;
				Date date_cl(date);

				lib_sign = "";
				lib_sign += ID[7];
				lib_sign += ID[8];
				lib_sign += ID[9];

				tmp2 = "";
				tmp2 += ID[1];
				tmp2 += ID[2];
				tmp2 += ID[3];
				tmp2 += ID[4];
				tmp2 += ID[5];
				tmp2 += ID[6];

				if (ID[0] == 'K')
				{
					Book book(ID, name, date_cl, title, is_available);
					Node<Book>* nodeb = new Node<Book>(book);
					library.books.push_front(nodeb);

					if (lib_sign.compare("GL1") == 0)
					{
						tmpcounter = (tmp2[0] - '0') * 100000 + (tmp2[1] - '0') * 10000 + (tmp2[2] - '0') * 1000 + (tmp2[3] - '0') * 100 + (tmp2[4] - '0') * 10 + (tmp2[5] - '0') ;
						if (tmpcounter > counter_books)
						{
							counter_books = tmpcounter;
							library.books.set_counter(counter_books);
						}
					}
				}
				else if (ID[0] == 'C')
				{
					CD cd(ID, name, date_cl, title, is_available);
					Node<CD>* nodec = new Node<CD>(cd);
					library.cds.push_front(nodec);

					if (lib_sign.compare("GL1") == 0)
					{
						tmpcounter = (tmp2[0] - '0') * 1000000 + (tmp2[1] - '0') * 100000 + (tmp2[2] - '0') * 10000 + (tmp2[3] - '0') * 1000 + (tmp2[4] - '0') * 100 + (tmp2[5] - '0') * 10 + (tmp2[6] - '0');
						if (tmpcounter > counter_cds)
						{
							counter_cds = tmpcounter;
							library.cds.set_counter(counter_cds);
						}
					}
				}
				else if (ID[0] == 'F')
				{
					Movie movie(ID, name, date_cl, title, is_available);
					Node<Movie>* nodem = new Node<Movie>(movie);
					library.movies.push_front(nodem);

					if (lib_sign.compare("GL1") == 0)
					{
						tmpcounter = (tmp2[0] - '0') * 1000000 + (tmp2[1] - '0') * 100000 + (tmp2[2] - '0') * 10000 + (tmp2[3] - '0') * 1000 + (tmp2[4] - '0') * 100 + (tmp2[5] - '0') * 10 + (tmp2[6] - '0');
						if (tmpcounter > counter_movies)
						{
							counter_movies = tmpcounter;
							library.movies.set_counter(counter_movies);
						}
					}
				}
				else
					continue;
			}
			else
			{
				if (i == 0)
					break;
				text.display_red(" Blad. Nieprawidlowy format pliku ");
				std::cout << this->filename << std::endl;
				break;
			}
		}
	}
	else
	{
		text.display_red(" Nie udalo sie otworzyc pliku ");
		std::cout << this->filename << std::endl;
	}
	file.close();
}


void FileLibrary::write(Library& library)
{

	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::out);

	if (this->check(file))
	{
		Node<Book>* tmpB = library.books.get_head();
		Node<CD>* tmpC = library.cds.get_head();
		Node<Movie>* tmpM = library.movies.get_head();

		while (tmpB)
		{
			file << tmpB->get_current_data().get_ID() << " ";
			file << tmpB->get_current_data().get_authors_name() << " ";
			file << tmpB->get_current_data().get_year_string() << " ";
			file << tmpB->get_current_data().get_availability() << " ";
			file << tmpB->get_current_data().get_title();

			tmpB = tmpB->get_next();
			if (tmpB || tmpC)
				file << std::endl;
		}

		while (tmpC)
		{
			file << tmpC->get_current_data().get_ID() << " ";
			file << tmpC->get_current_data().get_authors_name() << " ";
			file << tmpC->get_current_data().get_year_string() << " ";
			file << tmpC->get_current_data().get_availability() << " ";
			file << tmpC->get_current_data().get_title();

			tmpC = tmpC->get_next();
			if (tmpC || tmpM)
				file << std::endl;
		}
		while (tmpM)
		{
			file << tmpM->get_current_data().get_ID() << " ";
			file << tmpM->get_current_data().get_authors_name() << " ";
			file << tmpM->get_current_data().get_year_string() << " ";
			file << tmpM->get_current_data().get_availability() << " ";
			file << tmpM->get_current_data().get_title();

			tmpM = tmpM->get_next();
			if (tmpM)
				file << std::endl;
		}
		text.display_green(" Zapisano. ");
		std::cout << std::endl;
	}
	else
	{
		text.display_red(" Nie udalo sie otworzyc pliku ");
		std::cout << this->filename << std::endl;
	}

	file.close();
}