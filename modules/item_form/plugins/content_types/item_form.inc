<?php

/**
 * @file item_form.inc
 */
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
    'title' => t('Form'),
    'description' => t('Insert Form in pane.'),
    'single' => TRUE,
    'content_types' => array('item_form'),
    'render callback' => 'form_item_pane_render',
    'defaults' => array(),
    'edit form' => 'form_item_edit_form',
    //Make available all node tokens
    // @TODO Can I use two optional contexts in 'required context'? You could not before, but now it seems to work.
    /* 'required context' => array(
      new ctools_context_optional(t('Node'), 'node'),
      new ctools_context_optional(t('User'), 'user'),
      ), */
    /* 'icon' => 'icon_link.png', */
    'category' => array(t('Forms')),
);

/**
 * 'Edit form' callback for the content type.
 */
function form_item_edit_form($form, &$form_state) {
  ctools_include('export');
  $items = ctools_export_crud_load_all('item_form_forms');
  $options = array();
  foreach ($items as $name => $item) {
    $options[$name] = $name;
  }

  $conf = $form_state['conf'];

  $form['item_form'] = array(
      '#type' => 'select',
      '#title' => t('Item Forms'),
      '#description' => t('Choose Forms to display on this pane.'),
      '#options' => $options,
      '#default_value' => !empty($conf['item_form']) ? $conf['item_form'] : '',
  );

  return $form;
}

function form_item_edit_form_submit(&$form, &$form_state) {
  //Setting our choosed form type
  $form_state['conf']['item_form'] = $form_state['values']['item_form'];
}

/**
 * Create option list.
 */
function item_form_options() {
  ctools_include('export');
  $items = ctools_export_crud_load_all('item_form_forms');
  $options = array();
  foreach ($items as $name => $item) {
    $options[$name] = $name;
  }
  return $options;
}

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *
 * @return
 *   An object with at least title and content members.
 */
function form_item_pane_render($subtype, $conf, $args, $context) {
  
  $item_forms = array();

  $item_form_name = $conf['item_form'];

  ctools_include('export');
  $item_form = ctools_export_crud_load('item_form_forms', $item_form_name);

  $block = new stdClass();
  $block->title = t('Item Form');

  $block->content = '';
  
  /**
   * @todo Get rid of unserialize, use ctools_load
   */
  
  $form_conf = is_string($item_form->formdata) ? unserialize($item_form->formdata) : $item_form->formdata;
  
  $form = drupal_get_form('item_form_main_form', $form_conf);
  
  $block->content = drupal_render($form);
  

  return $block;
}

function item_form_main_form($form, $form_state, $item_form) {
  $form = array();
  
  $form['Amount'] = array(
      '#type' => 'select',
      '#title' => t('Select Ammount'),
      '#options' => explode(",", $item_form['settings']['sum_value_items']),
  );

  $form['application'] = array(
      '#type' => 'hidden',
      '#value' => $item_form['settings']['application'],
  );

  if (!$item_form['settings']['free_ammount']) {
    $form['free_ammount'] = array(
        '#type' => 'textfield',
        '#title' => t('Enter Ammount'),
        '#field_prefix' => '£',
    );
  }
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Send Money'),
  );

  return $form;
}

/**
 * @todo supply rendered form submission handler
 */