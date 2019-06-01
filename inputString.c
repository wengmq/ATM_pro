
int glb_putString(char str[], int iMaxLen, int iPutType, int isPlaintext)
{
	char ch;
	int iLenth = 0;
	while(1)
	{
		ch=getch();


		if(ch ==27)
		{
			return 0; //为esc时返回0

		}

		if(ch ==32)
		{
			return 2; //为空格时返回2

		}
		if(ch == '\r')
		{
			if( iLenth )									//输入不为空
			{
				str[iLenth] = '\0';
				break;
			}

				str[iLenth] = '\0';
				break;
		}
		if(ch == '\b')
		{
			if(iLenth > 0)
			{
				printf("\b \b");
				iLenth--;
				str[iLenth] = '\0';
			}
		}
		if(iLenth < iMaxLen)
		{
			switch(iPutType)
			{
				case 0:
					if(ch != '\b' && ch != '\r')
					{
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch; 
						iLenth++;

					}
				break;
				case 1:
					if (ch >= '0' && ch <= '9')
					{	
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch;
						iLenth++;
					}
				break;
				case 2:
					if ( ( ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z' ) )
					{
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch;
						iLenth++;
					}
				break;
				case 3:
					if ( ( ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z' ) || ( ch >= '0' && ch <= '9' ) )
					{
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch;
						iLenth++;
					}
				break;
			}
		
		}
	}

	return 1;

}



void putString(char str[], int iMaxLen, int iPutType, int isPlaintext)
{
	char ch;
	int iLenth = 0;
	while(1)
	{
		ch=getch();

		if(ch == '\r')
		{
			if( iLenth )									//输入不为空
			{
				str[iLenth] = '\0';
				break;
			}

				str[iLenth] = '\0';
				break;
		}
		if(ch == '\b')
		{
			if(iLenth > 0)
			{
				printf("\b \b");
				iLenth--;
				str[iLenth] = '\0';
			}
		}
		if(iLenth < iMaxLen)
		{
			switch(iPutType)
			{
				case 0:
					if(ch != '\b' && ch != '\r')
					{
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch; 
						iLenth++;

					}
				break;
				case 1:
					if (ch >= '0' && ch <= '9')
					{	
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch;
						iLenth++;
					}
				break;
				case 2:
					if ( ( ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z' ) )
					{
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch;
						iLenth++;
					}
				break;
				case 3:
					if ( ( ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z' ) || ( ch >= '0' && ch <= '9' ) )
					{
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch;
						iLenth++;
					}
				break;
			}
		
		}
	}



}





int time_putString(char str[], int iMaxLen)
{
	char ch;
	int iLenth = 0;
	int iPutType = 1;
	while(1)
	{
		ch=getch();


		if(ch ==27)
		{
			return 0; //为esc时返回0

		}

		if(ch ==32)
		{
			return 2; //为空格时返回2

		}	
		if( ch == 75)//左键
		{
			
		   return 75;
			
		}
		if( ch == 72)//上键
		{	
			return 72;
			
		}
		
		if(ch == 77 )//右键
		{
		return 77;
			
		}
		if(ch == 80)//下键
		{
			
		return 80;
			
		}
		if(ch == '\r')
		{
			if( iLenth )									//输入不为空
			{
				str[iLenth] = '\0';
				break;
			}

				str[iLenth] = '\0';
				break;
		}
		if(ch == '\b')
		{
			if(iLenth > 0)
			{
				printf("\b \b");
				iLenth--;
				str[iLenth] = '\0';
			}
		}
		if(iLenth < iMaxLen)
		{
			switch(iPutType)
			{

				case 1:
					if ((ch >= '0' && ch <= '9') || (ch =='-'))
					{	
					
						putchar(ch);
						str[iLenth] = ch;
						iLenth++;
					}
				break;
				
			}
		
		}
	}

	

}


int login_putString(char str[], int iMaxLen, int iPutType, int isPlaintext)
{
	char ch;
	int iLenth = 0;
	int position = 0;
	int x = 0;
	int i =0;
	int move = 0;
	char StringTemp[11] ={0};

	while(1)
	{
		ch=getch();


		move = iLenth-position;

		if(ch ==27)
		{
			return 0; //为esc时返回0

		}

		if(ch ==32)
		{
			return 2; //为空格时返回2

		}
		if(ch == '\r')
		{
			if( iLenth )//输入不为空
			{
				str[iLenth] = '\0';
				break;
			}

				str[iLenth] = '\0';
				break;
		}
		if(ch == '\b')
		{
			if(iLenth > 0)
			{
				printf("\b \b");
				iLenth--;
				str[iLenth] = '\0';
			}
		}

		if( ch == 75)//左键
		{
			if(position>0 && position< iMaxLen)
			{
			   printf("\b");
			   position--;
			}
			continue;
			
		}		
		if(ch == 77 )//右键
		{
			if(position>0 && position< iMaxLen)
				position++;
			continue;
			
		}

		
		if(iLenth < iMaxLen)
		{
			switch(iPutType)
			{
				case 0:
					if(ch != '\b' && ch != '\r')
					{
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch; 
						iLenth++;
						position++;

					}
				break;
				case 1:
					if (ch >= '0' && ch <= '9')
					{	
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch;
						iLenth++;
						position++;
					}
				break;
				case 2:
					if ( ( ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z' ) )
					{
						if (isPlaintext)
						{
							putchar(ch);
						}
						else
						{
							putchar('*');
						}
						str[iLenth] = ch;
						iLenth++;
						position++;
					}
				break;
				case 3:
					if ( ( ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z' ) || ( ch >= '0' && ch <= '9' ) )
					{
						if(move == 0)
						{
							if (isPlaintext)
							{
								putchar(ch);
							}
							else
							{
								putchar('*');
							}

							str[position] = ch;
							iLenth++;
							position++;
						}
						else
						{
							
							//iLenth++;
 
							i = 0;
							StringTemp[move] = '\0';
							
							for( x=iLenth-1 ;x>position-1;x--)
							{
								str[x] = str[x-1];
								StringTemp[--move] = str[x];

								if (isPlaintext)
								{
									putchar(ch);
									
								}
								else
								{
									putchar('*');
								}

							}

							printf("%s",StringTemp);
							for(i=0; i<iLenth-position ;i++)
							{
								printf("\b");
							}
							str[position] = ch;

						
						}
					}
				break;
			}
		
		}
	}

	return 1;

}




