using ull = unsigned long long;

ull exp_sum(unsigned int n)
{
  std::vector<ull> c(n+1,0); // array of coefficients of X^0 ... X^n
  c[0]=1;  // start with 1X^0
  for (unsigned int k = 1; k <= n; ++k) // multiply by 1/(1-X^k)
    for (unsigned int i = 0; (i + k) <= n; ++i)
      c[i + k]+=c[i];
  return c[n];
}