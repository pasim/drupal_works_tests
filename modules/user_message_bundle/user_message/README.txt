User message Module

1. Installation
  This module depends on User Revisions module - http://drupal.org/project/user_revision, it comes within user message
  bundle so;
  To get this on working first Install User Revisions module like any other drupal module
  Then enable User Message module
2. Configure permissions under admin/people/permissions, look for "User Live status message" and adjust properly

Then edit custom user message under user/id/edit, tick toogle box to enable display.

If you like to see Recent messages go to admin/structure/bocks and enable "User Messages: Recent" block.

This module uses a non traditional approach, Rather than creating custom tables via hook install it uses
Drupal 7 built in feature field API - more http://api.drupal.org/api/drupal/modules!field!field.module/group/field/7

If you need more comments how it was implemented drop me a line janis.janovskis@gmail.com

This module was tested with Drupal 7.22 installation

To do's;
Add cron support to purge outdated messages
Views integration
Ajax toogle block
