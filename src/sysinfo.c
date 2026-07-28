#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>
#include <stdint.h>

int main(){	
	char hostname[HOST_NAME_MAX + 1];
	int result = gethostname(hostname, sizeof(hostname));

	if(result == 0){
		printf("hostname: %s\n", hostname);
	}
	else{
		perror("gethostname");
		return 1;
	}

	long no_of_processors = sysconf(_SC_NPROCESSORS_CONF);
	if(no_of_processors == -1){
		perror("sysconf(_SC_NPROCESSORS_CONF)");
		return 1;
	}
	printf("no of processors: %ld\n", no_of_processors);

	long no_of_available_processors = sysconf(_SC_NPROCESSORS_ONLN);
	if(no_of_available_processors == -1){
		perror("sysconf(_SC_NPROCESSORS_ONLN)");
		return 1;
	}
	printf("no of available processors: %ld\n", no_of_available_processors);

	struct sysinfo info_obj;
	struct sysinfo* p_info_obj = &info_obj;

	int sysinfo_result = sysinfo(p_info_obj);
	if(sysinfo_result == -1){
		perror("sysinfo(p_info_obj)");
		return 1;
	}
	unsigned long total_ram;
	unsigned long free_ram;
	long uptime;
	unsigned int mem_unit;

	total_ram = p_info_obj->totalram;
	free_ram = p_info_obj->freeram;
	uptime = p_info_obj->uptime;
	mem_unit = p_info_obj->mem_unit;

	printf("total_ram: %lu\n",total_ram*mem_unit);
	printf("free_ram: %lu\n",free_ram*mem_unit);
	printf("uptime: %ld\n",uptime);
	printf("mem_unit: %u\n",mem_unit);

	struct statvfs statvfs_obj;
	int statvfs_result = statvfs("/", &statvfs_obj);
	if(statvfs_result == -1){
		perror("statvfs('/', &statvfs_obj)");
		return 1;
	}


	printf("Filesystem size: %ju\n",(uintmax_t)statvfs_obj.f_blocks);
	printf("Free blocks: %ju\n",(uintmax_t)statvfs_obj.f_bfree);
	printf("Available blocks: %ju\n",(uintmax_t)statvfs_obj.f_bavail);
	printf("Fragment size: %lu\n", statvfs_obj.f_frsize);


	return 0;
}
