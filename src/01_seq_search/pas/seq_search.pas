program PESQUISA_SEQUENCIAL;
uses sysutils,unix,unixutil,baseunix,Linux;

const 
  MAX_ITEMS = 10000;


var
  nome: array[1..MAX_ITEMS] of string;
  test_iterations: uint32;
  i: uint32;
  pesq: string;
  ipesq: uint32;
  start: TTimeSpec;
  finish: TTimeSpec;


function linear_search(key: string; arr: array of string): uint8;
begin
  for i := 1 to MAX_ITEMS do
  begin 
    if arr[i] = key then
    begin
      exit(1);
    end;
  end;
  exit(0);
end;


function random_string(): string;
var
  i: integer;
  res: string;
begin
  setLength(res, 10);
  for i:=1 to 10 do
    res[i] := chr(random(127-32)+32);
  exit(res);
end;


BEGIN
  for test_iterations := 1 to MAX_ITEMS do
  begin 
    { Init array }
    for i := 1 to MAX_ITEMS do
      nome[i] := random_string();

    ipesq := random(MAX_ITEMS);
    pesq := nome[ipesq];
    
    clock_gettime(CLOCK_MONOTONIC_RAW, @start);    
    linear_search(pesq, nome);    
    clock_gettime(CLOCK_MONOTONIC_RAW, @finish);    
    writeln(ipesq, ';', (finish.tv_sec - start.tv_sec) * 10000000000 + (finish.tv_nsec - start.tv_nsec));
  end;

END.
