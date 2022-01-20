#pragma once

#include <windows.h>
#include <assert.h>

typedef HANDLE pthread_t;
typedef CONDITION_VARIABLE pthread_cond_t;
typedef CRITICAL_SECTION pthread_mutex_t;

static inline int pthread_join(pthread_t thread, void **retval)
{
    assert(!retval);
	return WaitForSingleObject(thread, INFINITE);
}

struct thread_wrapper
{
	void *(*start_routine)(void*);
    void *arg;
};

static DWORD WINAPI thread_start(void *arg)
{
	struct thread_wrapper* wrap = arg;
    void *(*start_routine)(void *) = wrap->start_routine;
    void *orig_arg = wrap->arg;

    HeapFree(GetProcessHeap(), 0, wrap);

    return (ULONG_PTR)start_routine(orig_arg);
}

static inline int pthread_create(pthread_t *thread, const void *attr,
		void *(*start_routine)(void *), void *arg)
{
	DWORD tid;
	HANDLE t;
	struct thread_wrapper *wrap = HeapAlloc(GetProcessHeap(), 0, sizeof(*wrap));

    assert(!attr);

	if (!wrap)
		return -1;
	wrap->start_routine = start_routine;
	wrap->arg = arg;

	t = CreateThread(NULL, 0, thread_start, &wrap, 0, &tid);
	if (!t)
	{
		HeapFree(GetProcessHeap(), 0, wrap);
		return -1;
	}

	*thread = t;
	return 0;
}

static inline int pthread_mutex_init(pthread_mutex_t *mutex, const void *attr)
{
    assert(!attr);
    InitializeCriticalSection(mutex);
    return 0;
}

static inline int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
    DeleteCriticalSection(mutex);
    return 0;
}

static inline int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    EnterCriticalSection(mutex);
    return 0;
}

static inline int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
    LeaveCriticalSection(mutex);
    return 0;
}

static inline int pthread_cond_init(pthread_cond_t *cond, const void *attr)
{
    assert(!attr);
    InitializeConditionVariable(cond);
    return 0;
}

static inline int pthread_cond_destroy(pthread_cond_t *cond)
{
    return 0;
}

static inline int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex)
{
    SleepConditionVariableCS(cond, mutex, INFINITE);
    return 0;
}

static inline int pthread_cond_broadcast(pthread_cond_t *cond)
{
    WakeAllConditionVariable(cond);
    return 0;
}

static inline int pthread_cond_signal(pthread_cond_t *cond)
{
    WakeConditionVariable(cond);
    return 0;
}
