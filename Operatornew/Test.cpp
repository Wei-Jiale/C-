#include<iostream>

void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc){
	// try to allocate size bytes
	void *p;
	while ((p = malloc(size)) == 0)
	if (_callnewh(size) == 0){
		// report no memory
		// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
		static const std::bad_alloc nomem;
		_RAISE(nomem);
	}
	return (p);
}
