int factr (int n)
    {
	  int i;
      if (n<2)
        return 1 ;
      else
        return (n * factr(n-1)) ;
    }

    int main ()
    {
      int i = factr(7) ;
      return 0 ;
    }
