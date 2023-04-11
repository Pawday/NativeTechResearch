

#define MACRO 0

void dead_code(void);

#if MACRO
void dead_code(void)
{
	int a = 0;
	a++;
	return;
}
#endif

int main()
{
	if(MACRO)
		dead_code();
	return 100100;
}