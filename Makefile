CC=g++ -I src/include
CFLAGS=-c -Wall -Wextra -g3

all: GameOfChess run

GameOfChess: main.o Game.o DisplayManager.o Player.o ChessBoard.o Square.o King.o Pawn.o Knight.o Bishop.o Rook.o Queen.o RestrictedPiece.o Piece.o  
	$(CC) main.o Game.o DisplayManager.o Player.o ChessBoard.o Square.o King.o Pawn.o Knight.o Bishop.o Rook.o Queen.o RestrictedPiece.o Piece.o -o GameOfChess -L src/lib -l sfml-graphics -l sfml-window -l sfml-system

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) Game.cpp

DisplayManager.o: DisplayManager.cpp
	$(CC) $(CFLAGS) DisplayManager.cpp

Player.o: Player.cpp
	$(CC) $(CFLAGS) Player.cpp

ChessBoard.o: ChessBoard.cpp
	$(CC) $(CFLAGS) ChessBoard.cpp

Square.o: Square.cpp
	$(CC) $(CFLAGS) Square.cpp

King.o: King.cpp
	$(CC) $(CFLAGS) King.cpp

Pawn.o: Pawn.cpp
	$(CC) $(CFLAGS) Pawn.cpp

Knight.o: Knight.cpp
	$(CC) $(CFLAGS) Knight.cpp

Bishop.o: Bishop.cpp
	$(CC) $(CFLAGS) Bishop.cpp

Rook.o: Rook.cpp
	$(CC) $(CFLAGS) Rook.cpp
	
Queen.o: Queen.cpp
	$(CC) $(CFLAGS) Queen.cpp

RestrictedPiece.o: RestrictedPiece.cpp
	$(CC) $(CFLAGS) RestrictedPiece.cpp

Piece.o: Piece.cpp
	$(CC) $(CFLAGS) Piece.cpp

#.PHONY : clean

clean:
	del *.o GameOfChess.exe

run:
	./GameOfChess

test: #kompilacja i uruchomienie pliku testowego
	g++ -c test.cpp -I src/include
	g++ -I src/include test.o -o test -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
	del test.o
	./test