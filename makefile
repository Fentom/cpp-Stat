.SILENT:

LIB=$(HOME)/C++Stat2015/Lib

EXEC=lol testsample statistique
OBJ=$(LIB)/Data.o $(LIB)/Data1D.o $(LIB)/Data2D.o $(LIB)/DataSource.o $(LIB)/Fichier.o $(LIB)/Liste.o $(LIB)/ListeS.o $(LIB)/ListeTriee.o $(LIB)/DataSourceSerieDiscrete.o $(LIB)/DataSourceSerieContinue.o $(LIB)/DataSource2D.o $(LIB)/Echantillon.o $(LIB)/SerieStatistique1D.o $(LIB)/SerieStatistique2D.o $(LIB)/Utils.o

CC=g++ -I$(LIB)

all: $(EXEC)

lol:	test.cpp $(OBJ)
		echo Creation de lol executable
		$(CC) -o lol test.cpp $(OBJ)

testsample:	testSample.cpp $(OBJ)
		echo Creation de testsample executable
		$(CC) -o testsample testSample.cpp $(OBJ)

statistique:	main.cpp $(OBJ)
		echo Creation de statistique executable
		$(CC) -o statistique main.cpp $(OBJ)

$(LIB)/Utils.o:	$(LIB)/Utils.h $(LIB)/Utils.cpp
				echo Creation de Utils.o
				$(CC) -c $(LIB)/Utils.cpp -o $(LIB)/Utils.o

$(LIB)/Data.o:	$(LIB)/Data.h $(LIB)/Data.cpp
				echo Creation de Data.o
				$(CC) -c $(LIB)/Data.cpp -o $(LIB)/Data.o

$(LIB)/Data1D.o:	$(LIB)/Data1D.h $(LIB)/Data1D.cpp $(LIB)/Data.o 
				echo Creation de Data1D.o
				$(CC) -c $(LIB)/Data1D.cpp -o $(LIB)/Data1D.o

$(LIB)/Data2D.o:	$(LIB)/Data2D.h $(LIB)/Data2D.cpp $(LIB)/Data.o 
				echo Creation de Data2D.o
				$(CC) -c $(LIB)/Data2D.cpp -o $(LIB)/Data2D.o

$(LIB)/Liste.o:	$(LIB)/Liste.h $(LIB)/Liste.cpp
				echo Creation de Liste.o
				$(CC) -c $(LIB)/Liste.cpp -o $(LIB)/Liste.o

$(LIB)/ListeS.o:	$(LIB)/ListeS.h $(LIB)/ListeS.cpp $(LIB)/Liste.o 
				echo Creation de ListeS.o
				$(CC) -c $(LIB)/ListeS.cpp -o $(LIB)/ListeS.o

$(LIB)/ListeTriee.o:	$(LIB)/ListeTriee.h $(LIB)/ListeTriee.cpp $(LIB)/Liste.o 
				echo Creation de ListeTriee.o
				$(CC) -c $(LIB)/ListeTriee.cpp -o $(LIB)/ListeTriee.o

$(LIB)/Fichier.o:	$(LIB)/Fichier.h $(LIB)/Fichier.cpp $(LIB)/ListeS.o 
				echo Creation de Fichier.o
				$(CC) -c $(LIB)/Fichier.cpp -o $(LIB)/Fichier.o

$(LIB)/DataSource.o:	$(LIB)/DataSource.h $(LIB)/DataSource.cpp $(LIB)/ListeS.o $(LIB)/Utils.o
				echo Creation de DataSource.o
				$(CC) -c $(LIB)/DataSource.cpp -o $(LIB)/DataSource.o

$(LIB)/DataSourceSerieDiscrete.o:	$(LIB)/DataSourceSerieDiscrete.h $(LIB)/DataSourceSerieDiscrete.cpp $(LIB)/DataSource.o
				echo Creation de DataSourceSerieDiscrete.o
				$(CC) -c $(LIB)/DataSourceSerieDiscrete.cpp -o $(LIB)/DataSourceSerieDiscrete.o

$(LIB)/DataSourceSerieContinue.o:	$(LIB)/DataSourceSerieContinue.h $(LIB)/DataSourceSerieContinue.cpp $(LIB)/DataSource.o
				echo Creation de DataSourceSerieContinue.o
				$(CC) -c $(LIB)/DataSourceSerieContinue.cpp -o $(LIB)/DataSourceSerieContinue.o

$(LIB)/DataSource2D.o:	$(LIB)/DataSource2D.h $(LIB)/DataSource2D.cpp $(LIB)/DataSource.o
				echo Creation de DataSource2D.o
				$(CC) -c $(LIB)/DataSource2D.cpp -o $(LIB)/DataSource2D.o

$(LIB)/Echantillon.o:	$(LIB)/Echantillon.h $(LIB)/Echantillon.cpp $(LIB)/DataSource.o $(LIB)/ListeS.o $(LIB)/ListeTriee.o $(LIB)/Fichier.o
				echo Creation de Echantillon.o
				$(CC) -c $(LIB)/Echantillon.cpp -o $(LIB)/Echantillon.o

$(LIB)/SerieStatistique1D.o:	$(LIB)/SerieStatistique1D.h $(LIB)/SerieStatistique1D.cpp $(LIB)/Echantillon.o $(LIB)/DataSource.o $(LIB)/Liste.o
				echo Creation de SerieStatistique1D.o
				$(CC) -c $(LIB)/SerieStatistique1D.cpp -o $(LIB)/SerieStatistique1D.o

$(LIB)/SerieStatistique2D.o:	$(LIB)/SerieStatistique2D.h $(LIB)/SerieStatistique2D.cpp $(LIB)/DataSource2D.o $(LIB)/Echantillon.o
							echo Creation de SerieStatistique2D.o
							$(CC) -c $(LIB)/SerieStatistique2D.cpp -o $(LIB)/SerieStatistique2D.o
