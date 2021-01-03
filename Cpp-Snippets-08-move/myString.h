template <typename T>
void moveSwap(T & strA,  T & strB)
{
  T strTmp(move(strA));
  strA = move(strB);
  strB = move(strTmp);
}