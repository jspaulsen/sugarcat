#ifndef VEXPRESS_A9_H
#define VEXPRESS_A9_H
#include <types.h>
#include <linker.h>

void vexpress_init(unsigned int mach, addr_t atag_base);

/**
 * init_kvm_to_phy
 * Kernel Virtual Memory to Physical
 * 
 * converts a kernel virtual address to it's corresponding physical address
 * NOTE: this is only in the context of initialization.
 * 
 * @address		virtual address to convert
 * @return		physical address
 **/
inline addr_t init_kvm_to_phy(addr_t address) {
    addr_t kvm = (addr_t)&kv_start;
    addr_t kpm = (addr_t)&kp_start;
	
    return ((address & ~kvm) | kpm);
}

/**
 * init_phy_to_kvm
 * Physical to Kernel Virtual Memory
 * 
 * @address		physical address to convert
 * @return		virtual address
 **/
inline addr_t init_phy_to_kvm(addr_t address) {
    addr_t kvm = (addr_t)&kv_start;
    addr_t kpm = (addr_t)&kp_start;
	
    return ((address & ~kpm) | kvm);
}

#endif
