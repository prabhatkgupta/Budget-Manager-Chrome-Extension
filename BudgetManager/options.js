$(function(){

    chrome.storage.sync.get('limit',function(budget){
        $('#limit').val(budget.limit);
    });

    $('#saveLimit').click(function(){
        var limit = $('#limit').val();
        if (limit){
            chrome.storage.sync.set({'limit': limit}, function(){
                close();
            });
        }
    });

    $('#resetTotal').click(function(){
        chrome.storage.sync.set({'total': 0}, function(){
          
            var notifOptions = {
                type: "basic",
                iconUrl: "icon48.png",
                title: "Resetting Total",
                message: "Total has been reset to 0."
            };
           
            chrome.notifications.create('resetNotif', notifOptions);
           
        });
    });

     $(window).load(function() {
         setTimeout(function() {
                chrome.contextMenus.create(menuItem);

                chrome.contextMenus.onClicked.addListener(function(clickData){
                    if (clickData.menuItemId == "spendMoney" && clickData.selectionText){
                        if (isInt(clickData.selectionText)){
                            chrome.storage.sync.get(['total','limit'], function(budget){
                                var newTotal = 0;
                                if (budget.total){
                                    newTotal += parseInt(budget.total);
                                }

                                newTotal += parseInt(clickData.selectionText);
                                chrome.storage.sync.set({'total': newTotal}, function(){
                                if (newTotal >= budget.limit){
                                    var notifOptions = {
                                        type: "basic",
                                        iconUrl: "icon48.png",
                                        title: "Limit reached!",
                                        message: "Uh oh, look's like you've reached your alloted limit."
                                    };
                                    chrome.notifications.create('limitNotif', notifOptions);

                                    }
                                });
                            });
                        }
                    }
                });
             }
             ,1000
         )
     })
});