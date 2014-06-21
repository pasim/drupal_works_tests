/* 
 * @author janis.janovskis@gmail.com
 */

(function($){
  
  Drupal.behaviors.item_form_node = {
    attach : function(context, settings){
      var elem = $("<aside />");
      elem.css({
        "position" : "relative",
        "padding" : "2em",
        "background-color" : "#d6d6d6",
        "border" : "2px solid grey",
        "border-radius" : "8px",
        "margin" : "3em"
      });
      elem.addClass("info-node");
      
      var html = '<ul>';
      
      for (var key in settings.item_form_settings){
        if(settings.item_form_settings.hasOwnProperty(key)){
          html += "<li>" + key + " : " + settings.item_form_settings[key] + "</li>";
        }
      }
      html += "</ul>";
      elem.html(html);
      
      var kill = $("<div />");
      kill.text("Close X");
      kill.css({
        "color" : "grey",
        "position" : "absolute",
        "right" : "5%",
        "top" : "5%",
        "font-size" : "1.2em",
        "cursor" : "pointer"
      });
      
      kill.click(function(){
        $(this).parent().hide("slow");
      });
      
      elem.animate({
        padding : "2.2em",
        fontSize : "1.1em",
        opacity : 0.6,
        borderWidth: "6px"
      }, 2000);
      $("body").prepend(elem);
      elem.append(kill);
    }
  }
  
})(jQuery)

