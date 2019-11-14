#pragma once

typedef HANDLE pthread_t, pthread_mutex_t, pthread_cond_t;

static inline int pthread_join(pthread_t thread, void** retval)
{
	WaitForSingleObject(thread, INFINITE);
	return 0;
}

static inline int pthread_create(pthread_t *thread, const void *attr,
		void * (*start_routine)(void *), void *arg)
{
	DWORD tid;
	/* FIXME: Calling convention, retval */
	*thread = CreateThread(NULL, 0, (void *)start_routine, arg, 0, &tid);
	return tid;
}

static inline int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
	return -1;
}

static inline int pthread_mutex_init(pthread_mutex_t *mutex,
		const void *attr)
{
	return -1;
}

static inline int pthread_mutex_lock(pthread_mutex_t *mutex)
{
	return -1;
}

static inline int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
	return -1;
}

static inline int pthread_cond_destroy(pthread_cond_t *cond)
{
	return -1;
}

static inline int pthread_cond_init(pthread_cond_t *cond,
		const void *attr)
{
	return -1;
}

static inline int pthread_cond_wait(pthread_cond_t *cond,
	pthread_mutex_t *mutex)
{
	return -1;
}

static inline int pthread_cond_broadcast(pthread_cond_t *cond)
{
	return -1;
}

static inline int pthread_cond_signal(pthread_cond_t *cond)
{
	return -1;
}