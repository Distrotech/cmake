
#ifndef LINK_CXX_DEFINE
#error Expected LINK_CXX_DEFINE
#endif
#ifndef LINK_LANGUAGE_IS_CXX
#error Expected LINK_LANGUAGE_IS_CXX
#endif

#ifdef LINK_C_DEFINE
#error Unexpected LINK_C_DEFINE
#endif
#ifdef LINK_LANGUAGE_IS_C
#error Unexpected LINK_LANGUAGE_IS_C
#endif

void someFunc(void)
{

}
