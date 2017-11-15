#ifndef RUNTIME_ERROR_STUB_H_
#define RUNTIME_ERROR_STUB_H_
void RuntimeErrorStub_Reset(void);
const char *RuntimeErrorStub_GetLastError(void);
int RuntimeErrorStub_GetLastParameter(void);
#endif // RUNTIME_ERROR_STUB_H_
