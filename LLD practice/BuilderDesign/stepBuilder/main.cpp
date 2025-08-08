#include "IUrl.h"
#include "HttpRequestBuilder.h"
int main(){
    HttpRequest req = HttpRequestBuilder::getBuilder()
        .withUrl("https://example.com/api")
        .withMethod("POST")
        .withBody("Sample request body")
        .withHeader("Content-Type", "application/json")
        .withTimeout(30)
        .build();

        req.execute();
}