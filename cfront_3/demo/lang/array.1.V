template Array_RC<int> class

try_array: initial array values:
( 10 )< 12, 7, 14, 9, 128, 17
	6, 3, 27, 5 >

try_array: after assignments:
( 10 )< 128, 7, 14, 9, 128, 128
	6, 3, 27, 3 >

try_array: memberwise initialization
( 10 )< 128, 7, 14, 9, 128, 128
	6, 3, 27, 3 >

try_array: after memberwise copy
( 10 )< 128, 7, 128, 9, 128, 128
	6, 3, 27, 3 >

try_array: after grow
( 16 )< 128, 7, 128, 9, 128, 128
	6, 3, 27, 3, 0, 0
	0, 0, 0, 0 >

