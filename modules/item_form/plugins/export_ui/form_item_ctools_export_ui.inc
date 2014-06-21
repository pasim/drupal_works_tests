<?php

/**
 * Define this Export UI plugin.
 */
$plugin = array(
    'schema' => 'item_form_forms', // As defined in hook_schema().
    'access' => 'administer item_form', // Define a permission users must have to access these pages.
    // Define the menu item.
    'menu' => array(
        'menu item' => 'item_forms',
        'menu title' => 'Item Forms',
        'menu description' => 'Administer Item form presets.',
    ),
    // Define user interface texts.
    'title singular' => t('preset'),
    'title plural' => t('presets'),
    'title singular proper' => t('Item form preset'),
    'title plural proper' => t('Item form presets'),
    // Define the names of the functions that provide the add/edit forms.
    'form' => array(
        'settings' => 'item_form_ctools_export_ui_form',
    // 'submit' and 'validate' are also valid callbacks.
        'submit' => 'item_form_ctools_export_ui_form_submit',
    ),
);

function item_form_ctools_export_ui_form(&$form, &$form_state) {
  $preset = $form_state['item'];
  
  $formdata = unserialize($preset->formdata);

  $form['description'] = array(
      '#type' => 'textfield',
      '#title' => t('Form Description'),
      '#description' => t('The human readable name or description of form preset. Will appear on top of the form.'),
      '#default_value' => $preset->description,
      '#required' => true,
  );

  // Add Mymodule's configuration interface.

  $form['formdata'] = array(
      '#type' => 'fieldset',
      '#collapsible' => false,
      '#collapsed' => false,
      '#tree' => TRUE,
  );

  $form['formdata']['sum_value_items'] = array(
      '#type' => 'textfield',
      '#title' => t('Sum value items'),
      '#description' => t('Enter comma seperated list of values'),
      '#default_value' => $formdata['settings']['sum_value_items'],
      '#required' => true,
  );
  
  /**
   * @todo Make these apps as congigurable options
   */

  $app_options = array(
      'fbCoolAPP' => 'Great Facebook Application',
      'appBlank' => 'Blank Application',
      'kindOfAnApp' => 'Just For an App',
  );

  $form['formdata']['application'] = array(
      '#type' => 'select',
      '#title' => t('Application type'),
      '#options' => $app_options,
      '#description' => t('Choose application'),
      '#default_value' => $formdata['settings']['application'],
      '#required' => true,
  );
  $form['formdata']['free_ammount'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide free ammount field'),
      '#default_value' => $formdata['settings']['free_ammount'],
  );
}

function item_form_ctools_export_ui_form_submit($form, &$form_state){
  
  $form_state['values']['formdata'] = serialize(_item_form_formdata_flatten($form_state['values']['formdata']));
}

function _item_form_formdata_flatten($formdata){
  return array('settings'=>$formdata);
}