
class Solution:
    def crawl(self,startUrl,htmlParser):
        from threading import Thread,Lock 

    def get_hostname(url):
        return url.split('//',1)[1].split('/',1)[0]

    def fetch(url):
        for url in htmlParser.get_urls(url):
            with lock:
                if url in visited:
                    continue 
                visited.add(url)
            thread=Thread(target=fetch,args=(url,))
            thread.start()
            queue.append(thread)
        
    hostname = get_hostname(startUrl)
    lock=Lock()
    visited={startUrl}
    main_thread = Thread(target=fetch,args=(startUrl,))
    main_thread.start()
    queue=deque([main_thread])
    while queue:
        queue.pop_left().join()
    return list(visited)