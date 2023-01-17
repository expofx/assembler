# Assembler

Python usage: `python3 Assembler.py [file.asm]`

C++ usage: `g++ -o assembler Assembler.cpp Parser.cpp SymbolTable.cpp && ./assembler [file.asm]`

Benchmarking:
```
./assembler ../pong/Pong.asm  0.01s user 0.02s system 21% cpu 0.151 total
python3 Assembler.py ../pong/Pong.asm  0.11s user 0.01s system 51% cpu 0.225 tota
```