#define OOS (-65536)
#define SIZE (-1)
#define HEIGHT (0)
typedef int Item ;
typedef Item SetType   ;
typedef SetType *DisjiontSet ;
void InitializeAsHeight (DisjiontSet gather, const int size) ;
void InitializeAsSize (DisjiontSet gather, const int size) ;
int SetUnionAsHeight (DisjiontSet gather, SetType root1, SetType root2) ;
int SetUnionAsSize (DisjiontSet gather, SetType root1, SetType root2) ;
SetType Find (DisjiontSet gather, const Item item) ;
