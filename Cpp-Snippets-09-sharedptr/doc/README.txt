shared_ptr<T> is a shared ownership smart pointer. 
Several shared_ptr instances can share the management of an object's lifetime. 
The managed object is deleted when the last owning shared_ptr is destroyed.
